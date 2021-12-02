// system includes
#include <iostream>
#include <stdint.h>
#include <string.h>

// created includes
#include "MsgBuilder.h"
#include "Tooling.h"

// debug
#include "Debugging.h" // include > enables the ifdef DEBUG

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

ExRMessage MsgBuilder::GetExRMessage()
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

    std::cout << "CRC:" << unsigned(msg.crc) << std::endl;

    std::cout << msg.header[0] << " - ";
    std::cout << msg.header[1] << " - ";
    std::cout << msg.header[2] << " - ";
    std::cout << msg.header[3] << " - " << std::endl;

    std::cout << std::endl;

    std::cout << "BUILDED MESSAGE CONTENTS:" << std::endl;

    // uint8_t buffer[15];

    // memcpy(&buffer[15], (uint8_t *)&msg, 15);

    // std::cout << "BUFFER TYPE VALUES:" << std::endl; // causes buffer overflow error
    // for (int ii = 0; ii < sizeof(msg); ii++)
    // {
    //     printf("0x%02X \t", (uint8_t)(buffer[ii] & 0xff));
    // }
    // printf("\n");

    std::cout << "MSG-PRINTING TYPE VALUES:" << std::endl; // causes no problems, but displays different outcome?
    // print HEX values and remove last reserved byte
    for (int ii = 0; ii < sizeof(msg) - sizeof(uint8_t); ii++)
    {
        uint8_t val = (uint8_t)(((uint8_t *)&msg)[ii] & 0xFF);
        printf("0x%02X \t", val);
    }
    printf("\n");

    std::cout << "SERIAL_ADDR_BUILDED:" << unsigned(msg.serialId) << std::endl;

#endif // DEBUG
    return this->msg;
}