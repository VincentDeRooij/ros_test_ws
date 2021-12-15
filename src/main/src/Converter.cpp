// system includes

// created includes
#include "Converter.h"

uint32_fixed_t Int32ToUInt32Fixed(int32_t &inputValue, const std::uint8_t &iqValue)
{
    int32_t limit = (1 << (32 - iqValue - 1)) * 1000;
    if (inputValue > (limit - 1))
        inputValue = (limit - 1);
    else if (inputValue < -limit)
        inputValue = -limit;

    double value = (double)inputValue / 1000.0;
    return (uint32_fixed_t)value * (1 << iqValue);
}

//convert float to fixed point (uint32)
uint32_fixed_t FloatToFixedUInt32(double &inputValue, const std::uint8_t &iqValue)
{
    //Template Method
    return (uint32_fixed_t)inputValue * (1 << iqValue);
}

//convert fixed point (uint32) to float
double UInt32FixedToFloat(uint32_fixed_t &inputValue, const std::uint8_t &iqValue)
{
    return ((double)inputValue / (double)(1 << iqValue));
}

//convert fixed point (uint32) to int32  (assuming a ratio of 1000)
std::int32_t UInt32FixedToInt32(uint32_fixed_t &inputValue, const std::uint8_t &iqValue)
{
    return (std::int32_t)((double)inputValue / (double)(1 << iqValue) * 1000.0);
}