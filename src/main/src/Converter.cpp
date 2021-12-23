// system includes

// created includes
#include "Converter.h"

int32_t VolatileInt32ToUInt32Fixed(int32_t &inputValue, const std::uint8_t &iqValue)
{
    int32_t limit = (1 << (32 - iqValue - 1)) * 1000;
    if (inputValue > (limit - 1))
        inputValue = (limit - 1);
    else if (inputValue < -limit)
        inputValue = -limit;

    // calculate the fixed point number value
    uint32_t iq = 1 << iqValue;
    double value = (inputValue / 1000.0);
    int32_t val = value * iq;
    return val;
}

/**
 * @brief Converts a INT32 to a UINT32 Fixed
 * 
 * @param inputValue The INT32 that needs to be converted
 * @param iqValue  The IQ type that belongs to this value (IQ20/IQ24)
 * @return uint32_fixed_t The converted UINT32 Fixed
 */
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

/**
 * @brief Converts a Float to a UINT32 Fixed
 * 
 * @param inputValue The float that needs to be converted
 * @param iqValue The IQ type that belongs to this value (IQ20/IQ24)
 * @return uint32_fixed_t 
 */
uint32_fixed_t FloatToFixedUInt32(double &inputValue, const std::uint8_t &iqValue)
{
    //Template Method
    return (uint32_fixed_t)inputValue * (1 << iqValue);
}

/**
 * @brief Converts a UINT32 FIXED to a FLOAT
 * 
 * @param inputValue The UINT32 FIXED that needs to be converted
 * @param iqValue The IQ type that belongs to this value (IQ20/IQ24)
 * @return double 
 */
double UInt32FixedToFloat(uint32_fixed_t &inputValue, const std::uint8_t &iqValue)
{
    return ((double)inputValue / (double)(1 << iqValue));
}

/**
 * @brief Convert fixed point (uint32) to int32  (assuming a ratio of 1000)
 * 
 * @param inputValue The UINT32 Fixed that needs to be converted
 * @param iqValue The IQ type that belongs to this value (IQ20/IQ24)
 * @return std::int32_t 
 */
std::int32_t UInt32FixedToInt32(uint32_fixed_t &inputValue, const std::uint8_t &iqValue)
{
    return (std::int32_t)((double)inputValue / (double)(1 << iqValue) * 1000.0);
}