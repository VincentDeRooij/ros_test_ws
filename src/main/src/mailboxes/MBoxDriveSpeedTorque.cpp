#include "MBoxDriveSpeedTorque.h"
#include "Converter.h"

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

Payload MBoxDriveSpeedTorque::Write()
{
    Payload pl;

    copyInt32ToByteBuffer(this->maxAccelKRPM, &pl.payFull[0]);
    copyInt32ToByteBuffer(this->maxAccelKRPM, &pl.payFull[4]);

    return pl;
}

void MBoxDriveSpeedTorque::Set(void *dynamicMBoxStruct)
{
    DynamicAccelJerkPayload *dynamicPayload = (DynamicAccelJerkPayload *)dynamicMBoxStruct;

    // TIM CHECK REQUIRED?
    this->maxAccelKRPM = Int32ToUInt32Fixed(dynamicPayload->MAX_ACCEL_KRPM, IQ24);
    this->maxJerkKRPM = Int32ToUInt32Fixed(dynamicPayload->MAX_JERK_KRPM, IQ20);
}