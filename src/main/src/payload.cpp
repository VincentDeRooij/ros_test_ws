// system includes
#include <iostream>

// created includes
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

// OTHER CONSTRUCTOR TYPE? MAKES COMBINE METHOD OBSOLETE ( I think ;) )

// Payload::Payload(uint8_t pay_0, uint8_t pay_1, uint8_t pay_2, uint8_t pay_3, uint8_t pay_4, uint8_t pay_5, uint8_t pay_6, uint8_t pay_7)
// {
//     //setup payload object
//     this->pl_full[0] = pay_0;
//     this->pl_full[1] = pay_1;
//     this->pl_full[2] = pay_2;
//     this->pl_full[3] = pay_3;
//     this->pl_full[4] = pay_4;
//     this->pl_full[5] = pay_5;
//     this->pl_full[6] = pay_6;
//     this->pl_full[7] = pay_7;
    
// }

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
    combinePayload(); // With new constructor this method is not necessary -> check together :) 
    return this->pl_full;
}


// vvv NOTE vvv - We could add a call-by-ref uint8_t (uint8_t row) this one gets assigned by value 

// returns a certain row of the payload 
uint8_t Payload::getPayloadRow(int row)
{
    switch (row)
    {
    case 0:
        return this->pl_0;
        
        // Type 1
        // return this->pl_full[0]

        // Type 2
        // row = this->pl_full[0]; // gets assigned by call-by-ref
        // break;
    case 1:
        return this->pl_1;
        // return this->pl_full[1]
    case 2:
        return this->pl_2;
        // return this->pl_full[2]
    case 3:
        return this->pl_3;
        // return this->pl_full[3]
    case 4:
        return this->pl_4;
        // return this->pl_full[4]
    case 5:
        return this->pl_5;
        // return this->pl_full[5]
    case 6:
        return this->pl_6;
        // return this->pl_full[6]
    case 7:
        return this->pl_7;
        // return this->pl_full[7]
    default:
        std::cout << "The provided row isn't present" << std::endl;
        return 0;  
    }
}

// changes the data of a certain row to the user's provided data
void Payload::setPayloadRow(int row, uint8_t data)
{
    switch (row)
    {
    case 0:
        this->pl_0 = data;
        // this->pl_full[0] = data;
        break;
    case 1:
        this->pl_1 = data;
        // this->pl_full[1] = data;
        break;
    case 2:
        this->pl_2 = data;
        // this->pl_full[2] = data;
        break;
    case 3:
        this->pl_3 = data;
        // this->pl_full[3] = data;
        break;
    case 4:
        this->pl_4 = data;
        // this->pl_full[4] = data;
        break;
    case 5:
        this->pl_5 = data;
        // this->pl_full[5] = data;
        break;
    case 6:
        this->pl_6 = data;
        // this->pl_full[6] = data;
        break;
    case 7:
        this->pl_7 = data;
        // this->pl_full[7] = data;
        break;
    default:
        std::cout << "The row cannot be changed" << std::endl;
        break;
    }
}
