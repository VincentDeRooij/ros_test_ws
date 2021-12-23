#ifndef MBOXTEMPERATURES_H
#define MBOXTEMPERATURES_H
#pragma once

// Mailbox class
#include "Mailbox.h"

class MBoxTemperatures : public Mailbox //, ExROutput<ExRDataStructureTypeUInt[2]>
{
private:
    /**
 * @brief Output structure for this MBOX
 * 
 */
    struct MBoxOutStructureTemp
    {
        uint16_t MOSFET_TEMP; //MOSFET TEMPERATURE SENSOR ADC VALUE 0 to 65535
    };

    MBoxOutStructureTemp dataFields;

public:
    MBoxTemperatures() = default;
    ~MBoxTemperatures() = default;

    // inherit the method from mailbox, allowing our own method implementations
    void Read(Payload &p) override;
    void Set(void *dynamicMBoxStruct) override;
    Payload Write() override;
};
#endif