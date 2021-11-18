#ifndef __CONVERTER_H__
#define __CONVERTER_H__

// system includes
#include <cstdint>
#include <stdint.h>

#define Q24 24 // IQ24
#define Q20 20 // IQ20

typedef std::uint32_t uint32_fixed_t;

//convert int32 to fixed point (uint32) (assuming a ratio of 1000)
uint32_fixed_t IntToFixed(int32_t inputValue, std::uint8_t iqValue); 

//convert float to fixed point (uint32) 
uint32_fixed_t FloatToFixed(double inputValue, std::uint8_t iqValue);

//convert fixed point (uint32) to float
double FixedToFloat(uint32_fixed_t inputValue, std::uint8_t iqValue);

//convert fixed point (uint32) to int32  (assuming a ratio of 1000)
std::int32_t FixedToInt(uint32_fixed_t inputValue, std::uint8_t iqValue);

#endif // __CONVERTER_H__