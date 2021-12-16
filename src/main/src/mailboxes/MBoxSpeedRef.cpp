#include "MBoxSpeedRef.h"
#include "Converter.h"
#include "NotImplementedException.h"

Payload MBoxSpeedRef::Write()
{
    Payload pl;

    std::int32_t l = this->leftMotorDrive;
    std::int32_t r = this->rightMotorDrive;

    std::int32_t leftIQ = Int32ToUInt32Fixed(l, IQ24);
    std::int32_t rightIQ = Int32ToUInt32Fixed(r, IQ24);

    copyInt32ToByteBuffer(leftIQ, &pl.payFull[0]);
    copyInt32ToByteBuffer(rightIQ, &pl.payFull[4]);

    return pl;
}

void MBoxSpeedRef::Read(Payload &p)
{
    throw NotImplementedException();
}

void MBoxSpeedRef::Set(void *dynamicMBoxStruct)
{
    DynamicSpeedRefPayload *dynamicPayload = (DynamicSpeedRefPayload *)dynamicMBoxStruct;

    this->rightMotorDrive = dynamicPayload->RIGHT_MOTOR_DRIVE;
    this->leftMotorDrive = dynamicPayload->LEFT_MOTOR_DRIVE;
}