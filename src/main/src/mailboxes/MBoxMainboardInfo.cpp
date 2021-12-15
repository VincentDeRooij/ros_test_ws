#include "MBoxMainboardIOInfo.h"

MBoxMainboardIOInfo::MBoxMainboardIOInfo(const bool &lightIOPortOne, const bool &lightIOPortTwo, const bool &engineIOPort)
{
    this->engineIOPortIsEnabled = engineIOPort;
    this->lightIOPortOneIsEnabled = lightIOPortOne;
    this->lightIOPortTwoIsEnabled = lightIOPortTwo;
}

Payload MBoxMainboardIOInfo::Write()
{
    uint8_t byte = 0;

    setBitOnPos(byte, 0, this->lightIOPortOneIsEnabled);
    setBitOnPos(byte, 1, this->lightIOPortTwoIsEnabled);
    setBitOnPos(byte, 7, this->engineIOPortIsEnabled);

    Payload payload(0, 0, 0, 0, 0, 0, 0, byte);

    payload.PrintPayload();

    return payload;
}

void MBoxMainboardIOInfo::Read(Payload &p)
{
    // Read the first uint16 from the payload
    setBitsUInt16(this->dataFields.BAT_VOLTAGE, p.payFull[0], p.payFull[1]);

    // Read the second uint16 from the payload
    setBitsUInt16(this->dataFields.BAT_CHARGE_PERCENTAGE, p.payFull[2], p.payFull[3]);

    // Read the third int16 from the payload
    setBitsInt16(this->dataFields.BAT_AVR_CURRENT, p.payFull[4], p.payFull[5]);

    // lastly bind the fields of the two uint8 fields
    this->dataFields.MAINBOARD_INFO = p.payFull[6];
    this->dataFields.IO_EXPANDER_STATUS = p.payFull[7];

    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "BAT_VOLTAGE:" << unsigned(this->dataFields.BAT_VOLTAGE) << std::endl;
    std::cout << "BAT_CHARGE_PERCENTAGE:" << unsigned(this->dataFields.BAT_CHARGE_PERCENTAGE) << std::endl;
    std::cout << "BAT_AVR_CURRENT:" << unsigned(this->dataFields.BAT_AVR_CURRENT) << std::endl;
    std::cout << "MAINBOARD_INFO:" << unsigned(this->dataFields.MAINBOARD_INFO) << std::endl;
    std::cout << "IO_EXPANDER_STATUS:" << unsigned(this->dataFields.IO_EXPANDER_STATUS) << std::endl;
}