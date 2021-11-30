// system includes
#include <iostream>
#include <stdint.h>
#include <string.h>

// created includes
#include "msgbuilder.h"
#include "tooling.h"

// debug
#include "debugging_tools.h" // include > enables the ifdef DEBUG

MsgBuilder::MsgBuilder(const uint16_t serialId, const Payload payload)
{
    // fill the headers
    this->msg.header[0] = MSG_HF_1;
    this->msg.header[1] = MSG_HF_2;
    this->msg.header[2] = MSG_HF_3;
    this->msg.header[3] = MSG_HF_4;

    this->msg.crc = CRC_NULL_VALUE; // initialize a 'NULL' (0) value

    this->msg.serialId = serialId;

    mempcpy(&this->msg.payload, &payload, sizeof(PAYLOAD_MSG_SIZE)); // copies the data from payload to the msgbuilder struct // returns pointer of destination

    // uses call-by-ref to calc, and bind/check the crc field
    if (CalcCRCFromExRMessage(this->msg) == true)
    {
        // LOG CRC CORRECT
    }
}

ExrMessage MsgBuilder::GetExRMessage()
{
#ifdef DEBUG // debugging enable / disable

    std::cout << "Payload: ALLO_MEM Size Check: " << sizeof(this->msg.payload) << std::endl;
    std::cout << "Header: ALLO_MEM Size Check: " << sizeof(this->msg.header) << std::endl;
    std::cout << "CRC: ALLO_MEM Size Check: " << sizeof(this->msg.crc) << std::endl;
    std::cout << "SER-ID: ALLO_MEM Size Check: " << sizeof(this->msg.serialId) << std::endl;

    for (size_t i = 0; i < sizeof(msg.payload); i++)
    {
        std::cout << unsigned(((uint8_t *)&msg.payload)[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "CRC:" << unsigned(msg.crc) << unsigned(msg.crc) << std::endl;

    std::cout << msg.header[0] << " - ";
    std::cout << msg.header[1] << " - ";
    std::cout << msg.header[2] << " - ";
    std::cout << msg.header[3] << " - " << std::endl;

    std::cout << std::endl
              << std::endl;

#endif // DEBUG
    return this->msg;
}