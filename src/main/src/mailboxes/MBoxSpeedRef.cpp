#include "MBoxSpeedRef.h"
#include "Converter.h"

MBoxSpeedRef::MBoxSpeedRef(int8_t right, int8_t left)
{
    if (right > 4)
    {
        this->right = 4;
    }
    else if (right < -4)
    {
        this->right = -4;
    }
    else if (left > 4)
    {
        this->left = 4;
    }
    else if (left < -4)
    {
        this->left = 4;
    }
    else
    {
        this->left = left;
        this->right = right;
    }
}

Payload MBoxSpeedRef::Write()
{
    this->left = 1;
    this->right = 1;

    std::uint32_t l = this->left;
    std::uint32_t r = this->right;

    Payload pl;

    std::int32_t leftIQ = UInt32FixedToInt32(l, IQ24);
    std::int32_t rightIQ = UInt32FixedToInt32(r, IQ24);

    copyInt32ToByteBuffer(leftIQ, &pl.payFull[0]);
    copyInt32ToByteBuffer(rightIQ, &pl.payFull[4]);

    return pl;
}

void MBoxSpeedRef::Read(Payload &p)
{
    // EMPTY
}