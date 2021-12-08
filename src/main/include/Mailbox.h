#ifndef __MAILBOX_H__
#define __MAILBOX_H__

#include <stdint.h>
#include <vector>
#include <iostream>

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

public:
    //USE VIRTUAL WHEN INHERITING THESE METHODS!!!!
    //std::vector<enum>
};

#endif // __MAILBOX_H__