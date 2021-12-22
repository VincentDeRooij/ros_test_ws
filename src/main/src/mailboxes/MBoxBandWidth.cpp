#include "MBoxBandWidth.h"
#include "Converter.h"
#include "NotImplementedException.h"

MBoxBandWidth::MBoxBandWidth()
{
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
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
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxBandWidth::Set(void *dynamicMBoxStruct)
{
    // convert the void pointer type to the structure required
    DynamicBandwidthPayload *dynamicPayload = (DynamicBandwidthPayload *)dynamicMBoxStruct;

    // assign the values
    this->maxCurrent = dynamicPayload->MAX_CURRENT;
    this->controlBandwidth = dynamicPayload->CONTROL_BANDWIDTH;
}