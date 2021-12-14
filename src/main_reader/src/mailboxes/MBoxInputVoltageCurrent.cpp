#include "MBoxInputVoltageCurrent.h"

void MBoxInputVoltageCurrent::Read(Payload &p)
{
    // Read the first uint32 from the payload
    this->dataFields.VDCBUS_KV = p.getPayloadRow(0);
    this->dataFields.VDCBUS_KV = this->dataFields.VDCBUS_KV << 8;
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(1);
    this->dataFields.VDCBUS_KV = this->dataFields.VDCBUS_KV << 16;
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(2);
    this->dataFields.VDCBUS_KV = this->dataFields.VDCBUS_KV << 24;
    this->dataFields.VDCBUS_KV |= p.getPayloadRow(3);

    // Read the second uint32 from the payload
    this->dataFields.IQREF_A = p.getPayloadRow(4);
    this->dataFields.IQREF_A = this->dataFields.IQREF_A << 8;
    this->dataFields.IQREF_A |= p.getPayloadRow(5);
    this->dataFields.IQREF_A = this->dataFields.IQREF_A << 16;
    this->dataFields.IQREF_A |= p.getPayloadRow(6);
    this->dataFields.IQREF_A = this->dataFields.IQREF_A << 24;
    this->dataFields.IQREF_A |= p.getPayloadRow(7);
}