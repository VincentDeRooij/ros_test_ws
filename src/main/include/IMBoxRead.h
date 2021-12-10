#ifndef __IMBOXREAD_H__
#define __IMBOXREAD_H__

#include "Payload.h"

class IMBoxRead
{
    virtual void Read(Payload &p) = 0; // pure virtual
};

#endif // __IMBOXREAD_H__