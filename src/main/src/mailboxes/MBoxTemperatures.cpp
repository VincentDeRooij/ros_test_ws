#include "MBoxTemperatures.h"
#include "NotImplementedException.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
void MBoxTemperatures::Read(Payload &p)
{
    // Read the uint16 from the payload
    this->dataFields.MOSFET_TEMP = p.payFull[6] | (p.payFull[7] << 8);
    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "MOSFET_TEMP: " << unsigned(this->dataFields.MOSFET_TEMP) << std::endl;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
Payload MBoxTemperatures::Write()
{
    throw NotImplementedException();
}

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxTemperatures::Set(void *dynamicMBoxStruct)
{
    throw NotImplementedException();
}