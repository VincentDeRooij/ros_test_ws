// system includes
#include <unistd.h>
#include <iostream>

// created includes
#include "SerialValidationUtils.h"
#include "ExRSerialDefinitions.h"

/**
 * @brief 
 *  Checks the CRC or Calculates the CRC, this changes based on the starting value of the CRC field
 * @param msg This is the ExRMessage Object, use call-by-ref when assigning an ExRMessage variable inside the method
 * @return true: if a check was made, and the CRC field was calculated, or was equal to a previous value
 * @return false if an error occured/CRC field invalid
 */
bool CalcCRCFromExRMessage(ExRMessage &msg)
{
    std::cout << "CALCING...." << std::endl;
    uint8_t currentCRC = msg.crc; // sets the current CRC value for checking, if a current value was already found

    msg.crc = msg.header[0];
    msg.crc ^= msg.header[1];
    msg.crc ^= msg.header[2];
    msg.crc ^= msg.header[3];
    msg.crc ^= (msg.serialId & 0x00ff);
    msg.crc ^= (msg.serialId & 0xff00) >> 8;

    // fill the payload with empty data
    for (uint8_t index = 0; index < 8; index++)
    {
        msg.crc ^= msg.payload[index];
    }

    // checks the CALC type based on the currentCRC field
    if (currentCRC != CRC_NULL_VALUE) // if the current CRC value is not 'NULL' (0)
    {
        if (currentCRC == msg.crc) // if equal to current crc
        {
            std::cout << "CALCING_VALID...." << std::endl;
            //
            return true; // equal, message received is correct
        }
        std::cout << "CALCING_INVALID...." << std::endl;

        return false; // not equal, message received is not correct
    }
    std::cout << "CALCING_SIMPLE...." << std::endl;

    // a simple check was made
    return true;
}

/**
 * @brief 
 * first check which validates the Headers to check if the message
 * @param receivedMsg the received UART/Serial message to check
 * @return true if message headers are valid
 * @return false if message headers are invalid
 */
bool ValidateHeaders(ExRMessage &receivedMsg)
{
    std::cout << "VALIDATING...." << std::endl;

    bool valid = receivedMsg.header[0] == MSG_HF_1 && receivedMsg.header[1] == MSG_HF_2 && receivedMsg.header[2] == MSG_HF_3 && receivedMsg.header[3] == MSG_HF_4;

    std::cout << "MESSAGE_VAL_RESULT:" << valid << std::endl;
    return valid;
}
