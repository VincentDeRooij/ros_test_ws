#ifndef __MSGBUILDER_H__
#define __MSGBUILDER_H__
#pragma once

// system includes

// created includes
#include "exr_definitions.h"

class MsgBuilder
{
public:
    MsgBuilder(const uint16_t serialId, const Payload payload);
    MsgBuilder(MsgBuilder &&) = default;
    MsgBuilder(const MsgBuilder &) = default;
    MsgBuilder &operator=(MsgBuilder &&) = default;
    MsgBuilder &operator=(const MsgBuilder &) = default;
    ~MsgBuilder() = default;

    ExrMessage GetExRMessage();

private:
    ExrMessage msg;
};

#endif // __MSGBUILDER_H__