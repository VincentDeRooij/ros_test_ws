#include <iostream>
#include "payload.h"

Payload::Payload(uint8_t pay_0, uint8_t pay_1, uint8_t pay_2, uint8_t pay_3, uint8_t pay_4, uint8_t pay_5, uint8_t pay_6, uint8_t pay_7)
{
    //setup payload object
    this->pl_0 = pay_0;
    this->pl_1 = pay_1;
    this->pl_2 = pay_2;
    this->pl_3 = pay_3;
    this->pl_4 = pay_4;
    this->pl_5 = pay_5;
    this->pl_6 = pay_6;
    this->pl_7 = pay_7;
    
}

//Combining all 8 bytes into one full payload
void Payload::combinePayload()
{
    this->pl_full[0] = this->pl_0;
    this->pl_full[1] = this->pl_1;
    this->pl_full[2] = this->pl_2;
    this->pl_full[3] = this->pl_3;
    this->pl_full[4] = this->pl_4;
    this->pl_full[5] = this->pl_5;
    this->pl_full[6] = this->pl_6;
    this-> pl_full[7] = this->pl_7;

}
/*  returns the full Payload in uint8_t array form */
uint8_t* Payload::getPayloadFull()
{
    combinePayload();
    return this->pl_full;
}

// returns a certain row of the payload
uint8_t Payload::getPayloadRow(int row)
{
    switch (row)
    {
    case 0:
        return this->pl_0;
    case 1:
        return this->pl_1;
    case 2:
        return this->pl_2;
    case 3:
        return this->pl_3;
    case 4:
        return this->pl_4;
    case 5:
        return this->pl_5;
    case 6:
        return this->pl_6;
    case 7:
        return this->pl_7;
    default:
        std::cout << "The provided row isn't present" << std::endl;
        break;
    }
}

// changes the data of a certain row to the user's provided data
void Payload::setPayloadRow(int row, uint8_t data)
{
    switch (row)
    {
    case 0:
        this->pl_0 = data;
        break;
    case 1:
        this->pl_1 = data;
        break;
    case 2:
        this->pl_2 = data;
        break;
    case 3:
        this->pl_3 = data;
        break;
    case 4:
        this->pl_4 = data;
        break;
    case 5:
        this->pl_5 = data;
        break;
    case 6:
        this->pl_6 = data;
        break;
    case 7:
        this->pl_7 = data;
        break;
    default:
        std::cout << "The row cannot be changed" << std::endl;
        break;
    }
}
