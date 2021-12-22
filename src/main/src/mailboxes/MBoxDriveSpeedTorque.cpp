#include "MBoxDriveSpeedTorque.h"
#include "Converter.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
void MBoxDriveSpeedTorque::Read(Payload &p)
{
    // first SPEED_Kilo RPM
    setBitsUInt32(this->dataFields.SPEED_KRPM, p.payFull[3], p.payFull[2], p.payFull[1], p.payFull[0]);

    // second TORQUE_Newton Meter
    setBitsUInt32(this->dataFields.TORQUE_NEWTM, p.payFull[7], p.payFull[6], p.payFull[5], p.payFull[4]);

    // CONVERTING TO IQ24

    dataFields.SPEED_KRPM = UInt32FixedToInt32(dataFields.SPEED_KRPM, IQ24);
    dataFields.TORQUE_NEWTM = UInt32FixedToInt32(dataFields.TORQUE_NEWTM, IQ20);

    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "SPEED_KRPM: " << unsigned(this->dataFields.SPEED_KRPM) << std::endl;
    std::cout << "TORQUE_NEWTM: " << unsigned(this->dataFields.TORQUE_NEWTM) << std::endl;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
Payload MBoxDriveSpeedTorque::Write()
{
    Payload pl;

    copyInt32ToByteBuffer(this->maxAccelKRPM, &pl.payFull[0]);
    copyInt32ToByteBuffer(this->maxAccelKRPM, &pl.payFull[4]);

    return pl;
}

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxDriveSpeedTorque::Set(void *dynamicMBoxStruct)
{
    DynamicAccelJerkPayload *dynamicPayload = (DynamicAccelJerkPayload *)dynamicMBoxStruct;

    // TIM CHECK REQUIRED?
    this->maxAccelKRPM = Int32ToUInt32Fixed(dynamicPayload->MAX_ACCEL_KRPM, IQ24);
    this->maxJerkKRPM = Int32ToUInt32Fixed(dynamicPayload->MAX_JERK_KRPM, IQ20);
}