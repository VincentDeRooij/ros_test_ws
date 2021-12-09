#ifndef __EXRMSGSTRUCTURES_H__
#define __EXRMSGSTRUCTURES_H__

#include <stdint.h>
#include <string>

// >> NOTE This cannot be added later on, ExRMessage structure is static so it cannot be changed. STM handling requires certain structure to function

// An EXR message is build up of 15 bytes, where:
// > 4 bytes in total seperate makes the header fields
// > 2 bytes in total makes the the serial id field
// > 8 bytes in total makes the payload fields
// > 1 byte makes the crc field
struct ExRMessage //
{
    uint8_t header[4];  // 4 header fields of each 8 bits / 1 byte
    uint16_t serialId;  // serial address
    uint8_t payload[8]; // 8 payload data fields of each 8 bits / 1 byte
    uint8_t crc;        // checksum to check if message is complete
};

#endif // __EXRMSGSTRUCTURES_H__