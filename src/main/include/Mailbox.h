#ifndef __MAILBOX_H__
#define __MAILBOX_H__

#include <stdint.h>
#include <vector>
#include <iostream>

#include "Payload.h"

class Mailbox
{
protected:
    /**
     * @brief Set the Bit On Pos object
     * 
     * @param byte The call by reference byte on which bitshifting gets done 
     * @param pos The position of the bit (in a uint8) which needs to be set
     * @param enable The boolean which is used to see if a bit should be set
     */
    void setBitOnPos(uint8_t &byte, const uint8_t &pos, const bool &enable = true)
    {
        if (enable == true)
        {
            byte |= (1 << pos);
        }
    }

    void setLowNibbleBits(uint8_t &data, uint8_t &byteToNibble)
    {
        data |= byteToNibble & 0xf0;
    }

    void setHighNibbleBits(uint8_t &data, uint8_t &byteToNibble)
    {
        data |= (byteToNibble & 0xf0) >> 4;
    }

    void setBitsUInt16(uint16_t &data, uint8_t &byte_1, uint8_t &byte_2)
    {
        data = byte_1 | (byte_2 << 8);
    }

    void setBitsInt16(int16_t &data, uint8_t &byte_1, uint8_t &byte_2)
    {
        data = byte_1 | (byte_2 << 8);
    }

    void setBitsUInt32(uint32_t &data, uint8_t &byte_1, uint8_t &byte_2, uint8_t &byte_3, uint8_t &byte_4)
    {
        data = byte_4;
        data |= byte_3 << 8;
        data |= byte_2 << 16;
        data |= byte_1 << 24;
    }

    void setBitsInt32(int32_t &data, uint8_t &byte_1, uint8_t &byte_2, uint8_t &byte_3, uint8_t &byte_4)
    {
        data = byte_4;
        data |= byte_3 << 8;
        data |= byte_2 << 16;
        data |= byte_1 << 24;
    }

    void copyInt32ToByteBuffer(int32_t value, uint8_t *buffer)
    {
        buffer[3] = (value & 0x000000ff);
        buffer[2] = (value & 0x0000ff00) >> 8;
        buffer[1] = (value & 0x00ff0000) >> 16;
        buffer[0] = (value & 0xff000000) >> 24;
    }

public:
    virtual Payload Write() = 0;
    virtual void Read(Payload &p) = 0; // pure virtual

    //USE VIRTUAL WHEN INHERITING THESE METHODS!!!!
    //std::vector<enum>
};

#endif // __MAILBOX_H__