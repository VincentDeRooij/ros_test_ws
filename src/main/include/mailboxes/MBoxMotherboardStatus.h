#ifndef MBOXMOTHERBOARDSTATUS_H
#define MBOXMOTHERBOARDSTATUS_H
#pragma once

// Mailbox class
#include "Mailbox.h"

class MBoxMotherboardStatus : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
    /**
 * @brief Output structure for this MBOX
 * 
 */
    struct MBoxOutStructureMBStatus
    {
        uint8_t SOFTWARE_TYPE;       // Development or Production
        uint8_t SOFTWARE_VERSION;    // Version Number (0 - 15)
        uint8_t SOFTWARE_SUBVERSION; // Sub number (0 - 255)
        uint8_t INC_UART_ERR;        // Amount of UART Errors
        uint8_t I2C_ERR;             // IC2 error amount/fails
        uint8_t MAX_LOOP_TIME_DUR;   // MAX duration of while loop in MS
    };

    MBoxOutStructureMBStatus dataFields;

public:
    MBoxMotherboardStatus() = default;
    ~MBoxMotherboardStatus() = default;

    // inherit the method from mailbox, allowing our own method implementations
    void Read(Payload &p) override;
    void Set(void *dynamicMBoxStruct) override;
    Payload Write() override;
};
#endif