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

    PrintPayload();

#endif // DEBUG
}

/*  returns the full Payload in uint8_t array form */
uint8_t *Payload::getPayload()
{
    return this->payFull;
}

// returns a certain row of the payload
uint8_t Payload::getPayloadRow(const uint8_t &row)
{
    switch (row)
    {
    case 0:
        return this->payFull[0];
    case 1:
        return this->payFull[1];
    case 2:
        return this->payFull[2];
    case 3:
        return this->payFull[3];
    case 4:
        return this->payFull[4];
    case 5:
        return this->payFull[5];
    case 6:
        return this->payFull[6];
    case 7:
        return this->payFull[7];
    default:
        std::cout << "The provided row isn't present" << std::endl;
        return 0;
    }
}

// changes the data of a certain row to the user's provided data
void Payload::setPayloadRow(const uint8_t &row, const uint8_t &data)
{
    switch (row)
    {
    case 0:
        this->payFull[0] = data;
        break;
    case 1:
        this->payFull[1] = data;
        break;
    case 2:
        this->payFull[2] = data;
        break;
    case 3:
        this->payFull[3] = data;
        break;
    case 4:
        this->payFull[4] = data;
        break;
    case 5:
        this->payFull[5] = data;
        break;
    case 6:
        this->payFull[6] = data;
        break;
    case 7:
        this->payFull[7] = data;
        break;
    default:
        std::cout << "The row cannot be changed, or isn't present" << std::endl;
        break;
    }
}

void Payload::PrintPayload()
{
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << "PAYLOAD_CONTENT" << unsigned(this->payFull[i]) << " ";
    }
    std::cout << std::endl;
}
