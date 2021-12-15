// system includes
#include <iostream>

// created includes
#include "Payload.h"

// debug
#include "Debugging.h" // include > enables the ifdef DEBUG

Payload::Payload(const uint8_t &pay_0, const uint8_t &pay_1, const uint8_t &pay_2, const uint8_t &pay_3,
                 const uint8_t &pay_4, const uint8_t &pay_5, const uint8_t &pay_6, const uint8_t &pay_7)
{
    // //setup payload object
    this->payFull[0] = pay_0;
    this->payFull[1] = pay_1;
    this->payFull[2] = pay_2;
    this->payFull[3] = pay_3;
    this->payFull[4] = pay_4;
    this->payFull[5] = pay_5;
    this->payFull[6] = pay_6;
    this->payFull[7] = pay_7;

#ifdef DEBUG

    //PrintPayload();

#endif // DEBUG
}

void Payload::PrintPayload()
{
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << "PAYLOAD_CONTENT: " << unsigned(this->payFull[i]) << " ";
    }
    std::cout << std::endl;
}
