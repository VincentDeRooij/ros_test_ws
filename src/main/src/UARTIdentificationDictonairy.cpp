// system includes
#include <stdexcept>

// created includes
#include "UARTIdentificationDictionary.h"

/**
 * @brief Adds a entry to the Dictonairy 
 * 
 * @param sA Serial Adress
 * @param mBox The fitting Mailbox for the Serial Adress
 */
void UARTIdentificationDictionary::AddToMap(const uint16_t &sA, Mailbox &mBox)
{
    UARTIDDictionaryEntry a;

    a.address = sA;
    a.box = &mBox;

    m.push_back(a);

    std::cout << "ADDREE: " << m[0].address << std::endl;
}

Mailbox &UARTIdentificationDictionary::GetMailboxBySerial(const uint16_t &sId)
{

    for (UARTIDDictionaryEntry var : m)
    {
        if (var.address == sId)
        {
            std::cout << "FOUND AN ENTRY" << std::endl;
            return *var.box;
        }
    }
    std::cout << "NO ENTRY FOUND" << std::endl;

    throw std::exception();
}
