#include "MBoxDriveSettings.h"

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
        payload.setPayloadRow(7, 0b00111111);
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
    this->dataFields.TRAJECT_SPEED = p.getPayloadRow(0);
    this->dataFields.TRAJECT_SPEED = this->dataFields.TRAJECT_SPEED << 8;
    this->dataFields.TRAJECT_SPEED |= p.getPayloadRow(1);
    this->dataFields.TRAJECT_SPEED = this->dataFields.TRAJECT_SPEED << 16;
    this->dataFields.TRAJECT_SPEED |= p.getPayloadRow(2);
    this->dataFields.TRAJECT_SPEED = this->dataFields.TRAJECT_SPEED << 24;
    this->dataFields.TRAJECT_SPEED |= p.getPayloadRow(3);

    // second FIRMWARE VER
    this->dataFields.FIRMWARE_VER = p.getPayloadRow(4);
    // third AMPERE RATING
    this->dataFields.AMPERE_RATING = p.getPayloadRow(5);
    // fourth INFO STATE
    this->dataFields.INFO_STATES = p.getPayloadRow(6);
    // fifth ENGINE STATE TOGGLES
    this->dataFields.ENGINE_STATE_TOGGLES = p.getPayloadRow(7);
}