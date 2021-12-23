#ifndef __CONVERTER_H__
#define __CONVERTER_H__
#pragma once

// system includes
#include <cstdint>
#include <stdint.h>

#define IQ24 24 // IQ24
#define IQ20 20 // IQ20

typedef std::uint32_t uint32_fixed_t;

// Method which is used temporary
int32_t VolatileInt32ToUInt32Fixed(int32_t &inputValue, const std::uint8_t &iqValue);

//convert int32 to fixed point (uint32) (assuming a ratio of 1000)
uint32_fixed_t Int32ToUInt32Fixed(int32_t &inputValue, const std::uint8_t &iqValue);

//convert float to fixed point (uint32)
uint32_fixed_t FloatToFixedUInt32(double &inputValue, const std::uint8_t &iqValue);

//convert fixed point (uint32) to float
double UInt32FixedToFloat(uint32_fixed_t &inputValue, const std::uint8_t &iqValue);

//convert fixed point (uint32) to int32  (assuming a ratio of 1000)
std::int32_t UInt32FixedToInt32(uint32_fixed_t &inputValue, const std::uint8_t &iqValue);

#endif // __CONVERTER_H__