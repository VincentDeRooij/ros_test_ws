#include "msgbuilder.h"
#include <string.h>

MsgBuilder::MsgBuilder(const uint16_t serialId, const uint8_t payload[8])
{
    // fill the headers
    this->msg.header[0] = MSG_HF_1;
    this->msg.header[1] = MSG_HF_2;
    this->msg.header[2] = MSG_HF_3;
    this->msg.header[3] = MSG_HF_4;

    this->msg.serialId = serialId;

    mempcpy(&this->msg.payload, &payload, sizeof(PAYLOAD_MSG_SIZE)); // copies the data from payload to the msgbuilder struct // returns pointer of destination

    calcCrc();
}

ExrMessage* MsgBuilder::GetExRMessage()
{
    return &this->msg;
}

// calculate the checksum of the message
void MsgBuilder::calcCrc()
{      
    this->msg.crc  =  this->msg.header[0];
    this->msg.crc ^=  this->msg.header[1];
    this->msg.crc ^=  this->msg.header[2];
    this->msg.crc ^=  this->msg.header[3];
    this->msg.crc ^= (this->msg.serialId & 0x00ff);
    this->msg.crc ^= (this->msg.serialId & 0xff00) >> 8;
    
    // fill the payload with empty data
    for (uint8_t index=0;index<8;index++)
    {
        this->msg.crc ^= this->msg.payload[index];
    }
}