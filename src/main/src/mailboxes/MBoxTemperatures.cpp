#include "MBoxTemperatures.h"

void MBoxTemperatures::Read(Payload &p)
{
    // Read the uint16 from the payload
    this->dataFields.MOSFET_TEMP = p.payFull[6] | (p.payFull[7] << 8);
    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "MOSFET_TEMP: " << unsigned(this->dataFields.MOSFET_TEMP) << std::endl;
}

Payload MBoxTemperatures::Write()
{
    Payload a;

    return a;
}