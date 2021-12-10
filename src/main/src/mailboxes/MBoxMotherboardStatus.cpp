#include "MBoxMotherboardStatus.h"

void MBoxMotherboardStatus::Read(Payload &p)
{
    // Read the Low Nibble (4 bits)
    this->dataFields.SOFTWARE_TYPE = p.getPayloadRow(0);
    this->dataFields.SOFTWARE_TYPE = this->dataFields.SOFTWARE_TYPE & 0xf0;

    // Read the High Nibble (4 bits) -
    this->dataFields.SOFTWARE_VERSION = p.getPayloadRow(0);
    this->dataFields.SOFTWARE_VERSION = (this->dataFields.SOFTWARE_VERSION & 0xf0) >> 4;

    // Read the Software Subversion
    this->dataFields.SOFTWARE_SUBVERSION = p.getPayloadRow(1);
    // Read the Incoming UART errors
    this->dataFields.INC_UART_ERR = p.getPayloadRow(5);
    // Read amount I2C of errors
    this->dataFields.I2C_ERR = p.getPayloadRow(6);
    // Read the max loop duration in milli-seconds
    this->dataFields.MAX_LOOP_TIME_DUR = p.getPayloadRow(7);
}

Payload MBoxMotherboardStatus::Write()
{
    // Write empty payload
    return Payload();
}