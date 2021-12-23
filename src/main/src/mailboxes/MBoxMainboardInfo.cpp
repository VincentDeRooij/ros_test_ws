#include "MBoxMainboardIOInfo.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
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
    std::cout << "BAT_AVR_CURRENT:" << (this->dataFields.BAT_AVR_CURRENT) << std::endl;
    std::cout << "MAINBOARD_INFO:" << unsigned(this->dataFields.MAINBOARD_INFO) << std::endl;
    std::cout << "IO_EXPANDER_STATUS:" << unsigned(this->dataFields.IO_EXPANDER_STATUS) << std::endl;
}

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxMainboardIOInfo::Set(void *dynamicMBoxStruct)
{
    DynamicMainboardIOInfoPayload *dynamicPayload = (DynamicMainboardIOInfoPayload *)dynamicMBoxStruct;

    this->ioExpanderP7Motor = dynamicPayload->IO_Expander_P0_7_MOTOR;
    this->ioExpanderP1Light2 = dynamicPayload->IO_Expander_P0_1_LIGHT_2;
    this->ioExpanderP0Light1 = dynamicPayload->IO_Expander_P0_0_LIGHT_1;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
Payload MBoxMainboardIOInfo::Write()
{
    uint8_t byte = 0;

    setBitOnPos(byte, 0, this->ioExpanderP0Light1);
    setBitOnPos(byte, 1, this->ioExpanderP1Light2);
    setBitOnPos(byte, 7, this->ioExpanderP7Motor);

    Payload payload(0, 0, 0, 0, 0, 0, 0, byte);

    payload.PrintPayload();

    return payload;
}
