#include "MBoxSpeedRef.h"

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

    return Payload();
}

void MBoxSpeedRef::Read(Payload &p)
{
    // EMPTY
}