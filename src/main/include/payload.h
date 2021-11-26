#ifndef PAYLOAD_H
#define PAYLOAD_H
#pragma once

// system includes
#include <stdint.h>

class Payload
{
public:
        Payload() = default;
        Payload(uint8_t pay_0, uint8_t pay_1, uint8_t pay_2, uint8_t pay_3, uint8_t pay_4, uint8_t pay_5, uint8_t pay_6, uint8_t pay_7);

        uint8_t *getPayload();
        uint8_t getPayloadRow(int row);
        void setPayloadRow(int row, uint8_t data);

private:
        uint8_t payFull[8] = {}; // init an empty array
};
#endif