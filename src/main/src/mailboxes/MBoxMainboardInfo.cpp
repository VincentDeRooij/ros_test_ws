#include "MBoxMainboardInfo.h"

MBoxMainboardInfo::MBoxMainboardInfo(const bool &lightIOPortOne, const bool &lightIOPortTwo, const bool &engineIOPort)
{
    this->engineIOPortIsEnabled = engineIOPort;
    this->lightIOPortOneIsEnabled = lightIOPortOne;
    this->lightIOPortTwoIsEnabled = lightIOPortTwo;
}

MBoxMainboardInfo::~MBoxMainboardInfo()
{
}

Payload MBoxMainboardInfo::Write()
{
    uint8_t byte;

    setBitOnPos(byte, 0, this->lightIOPortOneIsEnabled);
    setBitOnPos(byte, 1, this->lightIOPortTwoIsEnabled);
    setBitOnPos(byte, 7, this->engineIOPortIsEnabled);

    Payload payload(0, 0, 0, 0, 0, 0, 0, byte);

    payload.PrintPayload();

    return payload;
}

void MBoxMainboardInfo::Read()
{
}