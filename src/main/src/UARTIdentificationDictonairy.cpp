// system includes

// created includes
#include "UARTIdentificationDictionary.h"
#include <stdexcept>

void UARTIdentificationDictionary::AddToMap(const uint16_t &sA, Mailbox *mBox, const bool &type)
{
    MBoxDriveSettings t(true);

    UARTIDDictionaryEntry a;
    a.address = sA;
    a.box = &t;
    a.isWriteType = type;

    m.push_back(a);

    std::cout << "ADDREE: " << m[0].address << std::endl;
}

Mailbox *UARTIdentificationDictionary::GetMailboxBySerial(const uint16_t &sId)
{

    for (UARTIDDictionaryEntry var : m)
    {
        if (var.address == sId)
        {
            std::cout << "HELLO I FOUND AN ENTRY" << std::endl;
            return var.box;
        }
    }
    throw std::exception();
}
