#include "MBoxSpeedRef.h"
#include "Converter.h"
#include "NotImplementedException.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
void MBoxSpeedRef::Read(Payload &p)
{
    throw NotImplementedException();
}

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxSpeedRef::Set(void *dynamicMBoxStruct)
{
    DynamicSpeedRefPayload *dynamicPayload = (DynamicSpeedRefPayload *)dynamicMBoxStruct;

    this->rightMotorDrive = dynamicPayload->RIGHT_MOTOR_DRIVE;
    this->leftMotorDrive = dynamicPayload->LEFT_MOTOR_DRIVE;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
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