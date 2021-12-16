#include "MBoxMotherboardStatus.h"
#include "NotImplementedException.h"

void MBoxMotherboardStatus::Read(Payload &p)
{
    // Read the Low Nibble (4 bits)
    setLowNibbleBits(this->dataFields.SOFTWARE_TYPE, p.payFull[0]);

    // Read the High Nibble (4 bits)
    setHighNibbleBits(this->dataFields.SOFTWARE_VERSION, p.payFull[0]);

    // Read the Software Subversion
    this->dataFields.SOFTWARE_SUBVERSION = p.payFull[1];
    // Read the Incoming UART errors
    this->dataFields.INC_UART_ERR = p.payFull[5];
    // Read amount I2C of errors
    this->dataFields.I2C_ERR = p.payFull[6];
    // Read the max loop duration in milli-seconds
    this->dataFields.MAX_LOOP_TIME_DUR = p.payFull[7];

    std::cout << "<<<<<READER VALUES>>>>>" << std::endl;
    std::cout << "SOFTW TYPE: " << unsigned(this->dataFields.SOFTWARE_TYPE) << std::endl;
    std::cout << "SOFTW VER: " << unsigned(this->dataFields.SOFTWARE_VERSION) << std::endl;
    std::cout << "SOFTW SUBVER: " << unsigned(this->dataFields.SOFTWARE_SUBVERSION) << std::endl;
    std::cout << "INC_UART_ERR: " << unsigned(this->dataFields.INC_UART_ERR) << std::endl;
    std::cout << "I2C_ERR: " << unsigned(this->dataFields.I2C_ERR) << std::endl;
    std::cout << "MAX_LOOP_TIM_DUR: " << unsigned(this->dataFields.MAX_LOOP_TIME_DUR) << std::endl;
}

Payload MBoxMotherboardStatus::Write()
{
    // Write empty payload
    return Payload();
}

void MBoxMotherboardStatus::Set(void *dynamicMBoxStruct)
{
    throw NotImplementedException();
}