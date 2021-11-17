#ifndef __MSGBUILDER_H__
#define __MSGBUILDER_H__

#include <stdint.h>

// An EXR message is build up of 15 bytes, where:
// > 4 bytes in total seperate makes the header fields
// > 2 bytes in total makes the the serial id field
// > 8 bytes in total makes the payload fields
// > 1 byte makes the crc field
struct ExrMessage // 
{
    uint8_t header[4]; // 4 header fields of each 8 bits / 1 byte
    uint16_t serialId; // serial address
    uint8_t payload[8]; // 8 payload data fields of each 8 bits / 1 byte
    int8_t crc; // checksum to check if message is complete
};

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