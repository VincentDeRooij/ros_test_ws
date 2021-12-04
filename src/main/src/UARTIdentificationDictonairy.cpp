// system includes

// created includes
#include "UARTIdentificationDictionary.h"   

void UARTIdentificationDictionary::AddToMap(const uint16_t &sA, Mailbox &mBox)
{
    this->m.insert(std::pair<uint16_t, std::shared_ptr<Mailbox *>>(sA, std::make_shared<Mailbox *>(&mBox)));
}

