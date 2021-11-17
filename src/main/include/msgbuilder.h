#ifndef __MSGBUILDER_H__
#define __MSGBUILDER_H__

#include "exr_definitions.h"

class MsgBuilder 
{
public:
    MsgBuilder(const uint16_t serialId, const uint8_t payload[8]);
    MsgBuilder(MsgBuilder &&) = default;
    MsgBuilder(const MsgBuilder &) = default;
    MsgBuilder &operator=(MsgBuilder &&) = default;
    MsgBuilder &operator=(const MsgBuilder &) = default;
    ~MsgBuilder() = default;

    ExrMessage* GetExRMessage();

private:
    ExrMessage msg;
    void calcCrc();
};

#endif // __MSGBUILDER_H__