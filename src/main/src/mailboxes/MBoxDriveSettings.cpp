#include "MBoxDriveSettings.h"
#include "Converter.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
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

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxDriveSettings::Set(void *dynamicMBoxStruct)
{
    DynamicDriveSettingsPayload *dynamicPayload = (DynamicDriveSettingsPayload *)dynamicMBoxStruct;

    this->enableOffsetCalc = dynamicPayload->ENABLE_OFFSET_CALC;
    this->enableForceAngle = dynamicPayload->ENABLE_FORCE_ANGLE;
    this->enableRSRecalc = dynamicPayload->ENABLE_RS_RECALC;
    this->enableUserParam = dynamicPayload->ENABLE_USER_PARAM;
    this->drvIdentity = dynamicPayload->DRV_IDENTIFY;
    this->drvEnable = dynamicPayload->DRV_ENABLE;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
Payload MBoxDriveSettings::Write()
{
    Payload payload;
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

    setBitsOnByte(payload.payFull[7], this->drvEnable, this->drvIdentity, this->enableUserParam, this->enableRSRecalc, this->enableForceAngle, this->enableOffsetCalc, false, false);

    return payload;
}