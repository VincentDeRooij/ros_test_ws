#include "MBoxInputVoltageCurrent.h"

void MBoxInputVoltageCurrent::Read(Payload &p)
{
    // Read the first uint32 from the payload
    this->dataFields.VDCBUS_KV = p.getPayloadRow(3);
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(2) << 8;
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(1) << 16;
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(0) << 24;

    // Read the second uint32 from the payload
    this->dataFields.IQREF_A = p.getPayloadRow(0);
    this->dataFields.IQREF_A |= p.getPayloadRow(1) << 8;
    this->dataFields.IQREF_A |= p.getPayloadRow(2) << 16;
    this->dataFields.IQREF_A |= p.getPayloadRow(3) << 24;
}

Payload MBoxInputVoltageCurrent::Write()
{
    Payload a;

    return a;
}