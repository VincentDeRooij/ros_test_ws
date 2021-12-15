#ifndef MBOXTEMPERATURES_H
#define MBOXTEMPERATURES_H
#pragma once

// Mailbox class
#include "Mailbox.h"

class MBoxTemperatures : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
    struct MBoxOutStructureTemp
    {
        uint16_t MOSFET_TEMP;
    };

    MBoxOutStructureTemp dataFields;

public:
    // Overrides from Mailbox
    Payload Write() override;
    void Read(Payload &p) override;

    MBoxTemperatures() = default;
    ~MBoxTemperatures() = default;
};
#endif