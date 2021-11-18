// system includes
#include <iostream>
#include <unistd.h>
#include <string.h>

// created includes
#include "msgbuilder.h"
#include "tooling.h"


MsgBuilder::MsgBuilder(const uint16_t serialId, const uint8_t payload[8])
{
    // fill the headers
    this->msg.header[0] = MSG_HF_1;
    this->msg.header[1] = MSG_HF_2;
    this->msg.header[2] = MSG_HF_3;
    this->msg.header[3] = MSG_HF_4;

    this->msg.crc = CRC_NULL_VALUE; // initialize a 'NULL' (0) value

    this->msg.serialId = serialId;

    mempcpy(&this->msg.payload, &payload, sizeof(PAYLOAD_MSG_SIZE)); // copies the data from payload to the msgbuilder struct // returns pointer of destination

    if (CalcCRCFromExRMessage(&this->msg) == true)
    {
        std::cout << "/* message */" << std::endl;
    }
}

ExrMessage* MsgBuilder::GetExRMessage()
{
    return &this->msg;
}