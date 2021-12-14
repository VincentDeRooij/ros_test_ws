// system includes

// created includes
#include "UARTIdentificationDictionary.h"

void UARTIdentificationDictionary::AddToMap(const uint16_t &sA, Mailbox *mBox)
{
    MBoxDriveSettings t(true);

    UARTIDDictionaryEntry a;
    a.address = sA;
    a.box = &t;

    m.push_back(a);
}
