#include "MBoxTemperatures.h"

void MBoxTemperatures::Read(Payload &p)
{
    // Read the uint16 from the payload
    this->dataFields.MOSFET_TEMP = p.getPayloadRow(6) | (p.getPayloadRow(7) << 8);
}

Payload MBoxTemperatures::Write()
{
    Payload a;

    return a;
}