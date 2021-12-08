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
    this->dataFields.SPEED_KRPM = p.getPayloadRow(0);
    this->dataFields.SPEED_KRPM = this->dataFields.SPEED_KRPM << 8;
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(1);
    this->dataFields.SPEED_KRPM = this->dataFields.SPEED_KRPM << 16;
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(2);
    this->dataFields.SPEED_KRPM = this->dataFields.SPEED_KRPM << 24;
    this->dataFields.SPEED_KRPM |= p.getPayloadRow(3);
    // second TORQUE_Newton Meter
    this->dataFields.TORQUE_NEWTM = p.getPayloadRow(4);
    this->dataFields.TORQUE_NEWTM = this->dataFields.TORQUE_NEWTM << 8;
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(5);
    this->dataFields.TORQUE_NEWTM = this->dataFields.TORQUE_NEWTM << 16;
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(6);
    this->dataFields.TORQUE_NEWTM = this->dataFields.TORQUE_NEWTM << 24;
    this->dataFields.TORQUE_NEWTM |= p.getPayloadRow(7);
}
