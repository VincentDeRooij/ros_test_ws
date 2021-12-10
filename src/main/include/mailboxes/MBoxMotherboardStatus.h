#ifndef MBOXMOTHERBOARDSTATUS_H
#define MBOXMOTHERBOARDSTATUS_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Mailbox Read Interface
#include "IMBoxRead.h"

// Mailbox Write Interface
#include "IMBoxWrite.h"

class MBoxMotherboardStatus : public Mailbox, public IMBoxRead, public IMBoxWrite //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
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
    // Overrides from Mailbox
    virtual void Read(Payload &p) override;
    virtual Payload Write() override;

    MBoxMotherboardStatus() = default;
    ~MBoxMotherboardStatus() = default;
};
#endif