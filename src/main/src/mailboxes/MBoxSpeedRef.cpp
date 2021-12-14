#include "MBoxSpeedRef.h"

MBoxSpeedRef::MBoxSpeedRef(int8_t right, int8_t left)
{
    this->left = left;
    this->right = right;
}

Payload MBoxSpeedRef::Write()
{
    return Payload();
}

void MBoxSpeedRef::Read(Payload &p)
{
    // EMPTY
}