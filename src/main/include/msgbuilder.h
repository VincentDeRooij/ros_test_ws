#ifndef __MSGBUILDER_H__
#define __MSGBUILDER_H__

#include <cstdint>

// message serial header values
#define MSG_HF_1 'a'
#define MSG_HF_2 'b'
#define MSG_HF_3 'c'
#define MSG_HF_4 'd'

// A EXR message is build up of 15 bytes, where:
// > 4 bytes in total seperate makes the header fields
// > 2 bytes in total makes the the serial id field
// > 8 bytes in total makes the payload fields
// > 1 byte makes the crc field
struct ExrMessage // 
{
    std::uint8_t header[4]; // 4 header fields of each 8 bits / 1 byte
    std::uint16_t serialId; // serial address
    std::uint8_t payload[8]; // 8 payload data fields of each 8 bits / 1 byte
    std::uint8_t crc; // checksum to check if message is complete
};

class MsgBuilder 
{
public:
    MsgBuilder(std::uint16_t serialId, std::uint8_t payload[8]);
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