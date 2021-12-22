#include "MBoxInputVoltageCurrent.h"
#include "Converter.h"
#include "NotImplementedException.h"

/**
 * @brief Reading the datafields and saving them in the right struct
 * 
 * @param p Payload received from Serial port
 */
void MBoxInputVoltageCurrent::Read(Payload &p)
{
    // Read the first uint32 from the payload
    setBitsUInt32(this->dataFields.VDCBUS_KV, p.payFull[3], p.payFull[2], p.payFull[1], p.payFull[0]);

    // Read the second uint32 from the payload
    setBitsUInt32(this->dataFields.IQREF_A, p.payFull[7], p.payFull[6], p.payFull[5], p.payFull[4]);

    //CONVERT TO IQ24
    dataFields.VDCBUS_KV = UInt32FixedToInt32(dataFields.VDCBUS_KV, IQ24);
    dataFields.IQREF_A = UInt32FixedToInt32(dataFields.IQREF_A, IQ24);

    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "VDCBUS_KV: " << unsigned(this->dataFields.VDCBUS_KV) << std::endl;
    std::cout << "IQREF_A: " << unsigned(this->dataFields.IQREF_A) << std::endl;
}

/**
 * @brief Returns a payload object belonging to the MBOX with correct bytecode
 * 
 * @return Payload with the bytecode for this MBOX
 */
Payload MBoxInputVoltageCurrent::Write()
{
    throw NotImplementedException();
}

/**
 * @brief The dynamic variables put into the Payload allowing dynamic changing of the payload
 * 
 * @param dynamicMBoxStruct The dynamic variables that need to be put in the payload
 */
void MBoxInputVoltageCurrent::Set(void *dynamicMBoxStruct)
{
    throw NotImplementedException();
}