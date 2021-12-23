#include "MBoxBandWidth.h"
#include "Converter.h"

// custom exceptions
#include "NotImplementedException.h"

// Limit definitions
#define MAX_BW_CURRENT 0
#define MAX_BANDWIDTH 20

/**
 * @brief Exception implementation of the MBoxBandWidth Class
 * This will handle the limit input, and will set fail-safe values when values exceed their max/min-(imums)
 * 
 * @param payloadType The same dynamic payload type (void*)  
 * @return const char* The return message of the exception
 */
const char *MBoxBandWidth::what(void *payloadType) throw()
{
    std::cout << "Value incorrect/unsafe! Adjusting to fail-safe values..." << std::endl;
    DynamicBandwidthPayload *dynamicPayload = (DynamicBandwidthPayload *)payloadType;

    // apply the standard values
    dynamicPayload->CONTROL_BANDWIDTH = 20;
    dynamicPayload->MAX_CURRENT = 0;

    return "Fail-safe values applied!";
}

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
void MBoxBandWidth::Read(Payload &p)
{
    // EMPTY
    throw NotImplementedException();
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxBandWidth::Set(void *dynamicMBoxStruct)
{
    // convert the void pointer type to the structure required
    DynamicBandwidthPayload *dynamicPayload = (DynamicBandwidthPayload *)dynamicMBoxStruct;

    try
    {
        std::cout << "Checking min/max values for bandwidth..." << std::endl;

        bool withinBw = dynamicPayload->CONTROL_BANDWIDTH == MAX_BANDWIDTH;   //  if higher than 20
        bool withinBwCurrent = dynamicPayload->MAX_CURRENT == MAX_BW_CURRENT; // if not equal to 0

        if (!withinBw || !withinBwCurrent)
        {
            throw MBoxBandWidth();
        }
    }
    catch (const IValueLimitException &e)
    {
        std::cerr << what(&dynamicPayload) << '\n';
    }

    // assign the values
    this->maxCurrent = dynamicPayload->MAX_CURRENT;
    this->controlBandwidth = dynamicPayload->CONTROL_BANDWIDTH;
}

Payload MBoxBandWidth::Write()
{
    Payload pl;
    int32_t bwCurrent = this->maxCurrent;
    int32_t controlBw = this->controlBandwidth;

    uint32_t bwCurrentConv = Int32ToUInt32Fixed(bwCurrent, IQ24);
    uint32_t controlBwConv = Int32ToUInt32Fixed(controlBw, IQ20);

    copyInt32ToByteBuffer(bwCurrentConv, &pl.payFull[0]);
    copyInt32ToByteBuffer(controlBwConv, &pl.payFull[4]);

    return pl;
}