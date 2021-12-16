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
        uint16_t MOSFET_TEMP; //MOSFET TEMPERATURE SENSOR ADC VALUE 0 to 65535
    };

    MBoxOutStructureTemp dataFields;

public:
    // Overrides from Mailbox
    Payload Write() override;
    void Read(Payload &p) override;
    void Set(void *structure);

    MBoxTemperatures() = default;
    ~MBoxTemperatures() = default;
};
#endif