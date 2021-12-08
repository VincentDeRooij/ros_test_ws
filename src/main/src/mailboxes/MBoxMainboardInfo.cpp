#include "MBoxMainboardInfo.h"

MBoxMainboardInfo::MBoxMainboardInfo(const bool &lightIOPortOne, const bool &lightIOPortTwo, const bool &engineIOPort)
{
    this->engineIOPortIsEnabled = engineIOPort;
    this->lightIOPortOneIsEnabled = lightIOPortOne;
    this->lightIOPortTwoIsEnabled = lightIOPortTwo;
}

Payload MBoxMainboardInfo::Write()
{
    uint8_t byte = 0;

    setBitOnPos(byte, 0, this->lightIOPortOneIsEnabled);
    setBitOnPos(byte, 1, this->lightIOPortTwoIsEnabled);
    setBitOnPos(byte, 7, this->engineIOPortIsEnabled);

    Payload payload(0, 0, 0, 0, 0, 0, 0, byte);

    payload.PrintPayload();

    return payload;
}

void MBoxMainboardInfo::Read(Payload &p)
{
    // Read the first uint16 from the payload
    this->dataFields.BAT_VOLTAGE = p.getPayloadRow(0);
    this->dataFields.BAT_VOLTAGE = this->dataFields.BAT_VOLTAGE << 8;
    this->dataFields.BAT_VOLTAGE |= p.getPayloadRow(1);

    // Read the second uint16 from the payload
    this->dataFields.BAT_CHARGE_PERCENTAGE = p.getPayloadRow(2);
    this->dataFields.BAT_CHARGE_PERCENTAGE = this->dataFields.BAT_CHARGE_PERCENTAGE << 8;
    this->dataFields.BAT_CHARGE_PERCENTAGE |= p.getPayloadRow(3);

    // Read the third int16 from the payload
    this->dataFields.BAT_AVR_CURRENT = p.getPayloadRow(4);
    this->dataFields.BAT_AVR_CURRENT = this->dataFields.BAT_AVR_CURRENT << 8;
    this->dataFields.BAT_AVR_CURRENT |= p.getPayloadRow(5);

    // lastly bind the fields of the two uint8 fields
    this->dataFields.MAINBOARD_INFO = p.getPayloadRow(6);
    this->dataFields.IO_EXPANDER_STATUS = p.getPayloadRow(7);

    // std::cout << "Volt:" << unsigned(this->dataFields.BAT_VOLTAGE) << std::endl;
    // std::cout << "Charge:" << unsigned(this->dataFields.BAT_CHARGE_PERCENTAGE) << std::endl;
    // std::cout << "AVR_C:" << unsigned(this->dataFields.BAT_AVR_CURRENT) << std::endl;
    // std::cout << "Info:" << unsigned(this->dataFields.MAINBOARD_INFO) << std::endl;
    // std::cout << "Expander:" << unsigned(this->dataFields.IO_EXPANDER_STATUS) << std::endl;
}