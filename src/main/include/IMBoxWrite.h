#ifndef __IMBOXWRITE_H__
#define __IMBOXWRITE_H__

#include "Payload.h"

class IMBoxWrite
{
    virtual Payload Write() = 0; // pure virtual
};

#endif // __IMBOXWRITE_H__