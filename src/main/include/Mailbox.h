#ifndef __MAILBOX_INTERFACE_H__
#define __MAILBOX_INTERFACE_H__

#include "ExRDefinitions.h"

class Mailbox
{
protected:
    ExRMessage msg;

public: //USE VIRTUAL WHEN INHERITING THESE METHODS!!!! 
    virtual ~Mailbox() = default;
    virtual void Write() = 0;
    virtual void Read() = 0;
};

#endif // __MAILBOX_INTERFACE_H__