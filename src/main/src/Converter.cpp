// system includes

// created includes
#include "Converter.h"

uint32_fixed_t IntToFixed(int32_t inputValue, std::uint8_t iqValue)
{
    //int32_t limitValue = (1 << (32 - iqValue - 1)) * 1000;

    double value = (double)inputValue / 1000.0;
    return (uint32_fixed_t)inputValue * (1 << iqValue);
}

//convert float to fixed point (uint32)
uint32_fixed_t FloatToFixed(double inputValue, std::uint8_t iqValue)
{
    //Template Method
    return (uint32_fixed_t)inputValue * (1 << iqValue);
}

//convert fixed point (uint32) to float
double FixedToFloat(uint32_fixed_t inputValue, std::uint8_t iqValue)
{
    //Template Method
    double floater;

    return floater;
}

//convert fixed point (uint32) to int32  (assuming a ratio of 1000)
std::int32_t FixedToInt(uint32_fixed_t inputValue, std::uint8_t iqValue)
{
    //Template Method
    std::int32_t int32Fixed;

    return int32Fixed;
}