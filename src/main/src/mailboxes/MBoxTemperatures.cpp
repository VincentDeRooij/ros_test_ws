#include "MBoxTemperatures.h"

void MBoxTemperatures::Read(Payload &p)
{
    // Read the uint16 from the payload
    this->dataFields.MOSFET_TEMP = p.getPayloadRow(6);
    this->dataFields.MOSFET_TEMP = this->dataFields.MOSFET_TEMP << 8;
    this->dataFields.MOSFET_TEMP |= p.getPayloadRow(7);


}