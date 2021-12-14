#include "MBoxDriveSpeedTorque.h"

// MBoxDriveSpeedTorque::MBoxDriveSpeedTorque()
// {
// }

// MBoxDriveSpeedTorque::~MBoxDriveSpeedTorque()
// {
// }

void MBoxDriveSpeedTorque::Read(Payload &p)
{
    // first SPEED_Kilo RPM
    this->dataFields.SPEED_KRPM = p.getPayloadRow(3);
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(2) << 8;
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(1) << 16;
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(0) << 24;
    // second TORQUE_Newton Meter
    this->dataFields.TORQUE_NEWTM = p.getPayloadRow(3);
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(2) << 8;
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(1) << 16;
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(0) << 24;
}

Payload MBoxDriveSpeedTorque::Write()
{
    Payload a;

    return a;
}