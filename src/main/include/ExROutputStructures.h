#ifndef __EXROUTPUTSTRUCTURES_H__
#define __EXROUTPUTSTRUCTURES_H__

#include <stdint.h>
#include <string>

// More Types?

// Type used for the Mailboxes - 0x111
struct ExRODataStructureTypeInt
{
    std::string field; // Field name identifier (for logging)
    uint8_t type;      // If the field is of IQ20 or IQ24 type
    int32_t value;     // value in IQ20/IQ24 (spread over a int32 type)
};

// Type used for the Mailboxes - 0x131, 0x121, 0x123, 0x113
struct ExRDataStructureTypeUInt
{
    std::string field; // Field name identifier (for logging)
    uint8_t type;      // If the field is of IQ20 or IQ24 type
    uint32_t value;    // value in IQ20/IQ24 (spread over a uint32_t type)
};

#endif // __EXROUTPUTSTRUCTURES_H__