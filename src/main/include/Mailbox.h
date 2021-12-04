#ifndef __MAILBOX_H__
#define __MAILBOX_H__

#include <stdint.h>
#include <iostream>

#include "Payload.h"

class Mailbox
{
protected:
    // ExRMessage msg;
    // Payload payload;

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
            (1 << pos) | byte;
        }
    }

public: //USE VIRTUAL WHEN INHERITING THESE METHODS!!!!
    Mailbox() = default;
    virtual ~Mailbox() = default;
    virtual Payload Write() = 0; // pure virtual
    virtual void Read() = 0;     // pure virtual
};

#endif // __MAILBOX_H__