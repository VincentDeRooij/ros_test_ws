#include "MBoxDriveSettings.h"
#include "Converter.h"

MBoxDriveSettings::MBoxDriveSettings(const bool &engineEnabled)
{
    this->engineIsEnabled = engineEnabled;
}

MBoxDriveSettings::~MBoxDriveSettings()
{
}

Payload MBoxDriveSettings::Write()
{
    Payload payload;

    if (this->engineIsEnabled == true)
    {
        //>> Not relevant
        // BIT(7)=0   I2T FILTER
        // BIT(6)=0   POWERWARP

        //>> important
        // BIT(5)=1   ENABLE_OFFSET_CALC
        // BIT(4)=1   ENABLE_FORCE_ANGLE
        // BIT(3)=1   ENABLE_RS_RECALC
        // BIT(2)=1   ENABLE_USER_PARAM
        // BIT(1)=1   DRV_INDENTIFY
        // BIT(0)=1   DRV_ENABLE

        // fill byte 7 with the required data to enable the Engine
        payload.payFull[7] = 0b00111111;
    }
    else
    {
        //>> Not relevant
        // BIT(7)=0   I2T FILTER
        // BIT(6)=0   POWERWARP

        //>> important
        // BIT(5)=0   ENABLE_OFFSET_CALC
        // BIT(4)=0   ENABLE_FORCE_ANGLE
        // BIT(3)=0   ENABLE_RS_RECALC
        // BIT(2)=0   ENABLE_USER_PARAM
        // BIT(1)=0   DRV_INDENTIFY
        // BIT(0)=0   DRV_ENABLE

        Payload payload(0, 0, 0, 0, 0, 0, 0, 0); // set payload to all zero's and reserved space
    }

    payload.PrintPayload();

    return payload;
}

void MBoxDriveSettings::Read(Payload &p)
{
    // first TRAJECTORY SPEED
    setBitsUInt32(this->dataFields.TRAJECT_SPEED, p.payFull[3], p.payFull[2], p.payFull[1], p.payFull[0]);

    // second FIRMWARE VER
    this->dataFields.FIRMWARE_VER = p.payFull[4];
    // third AMPERE RATING
    this->dataFields.AMPERE_RATING = p.payFull[5];
    // fourth INFO STATE
    this->dataFields.INFO_STATES = p.payFull[6];
    // fifth ENGINE STATE TOGGLES
    this->dataFields.ENGINE_STATE_TOGGLES = p.payFull[7];

    dataFields.TRAJECT_SPEED = UInt32FixedToInt32(dataFields.TRAJECT_SPEED, IQ24);

    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "TRAJECT_SPEED:" << unsigned(this->dataFields.TRAJECT_SPEED) << std::endl;
    std::cout << "FIRMWARE_VER:" << unsigned(this->dataFields.FIRMWARE_VER) << std::endl;
    std::cout << "AMPERE_RATING:" << unsigned(this->dataFields.AMPERE_RATING) << std::endl;
    std::cout << "INFO_STATES:" << unsigned(this->dataFields.INFO_STATES) << std::endl;
    std::cout << "ENGINE_STATE_TOGGLES:" << unsigned(this->dataFields.ENGINE_STATE_TOGGLES) << std::endl;
}