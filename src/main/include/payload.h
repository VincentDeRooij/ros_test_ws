#ifndef PAYLOAD_H
#define PAYLOAD_H
#pragma once

// system includes
#include <stdint.h>

class Payload
{
public:
        Payload() = default;
        Payload(const uint8_t &pay_0, const uint8_t &pay_1, const uint8_t &pay_2, const uint8_t &pay_3, const uint8_t &pay_4, const uint8_t &pay_5, const uint8_t &pay_6, const uint8_t &pay_7);

        uint8_t *getPayload();
        uint8_t getPayloadRow(int row);
        void setPayloadRow(int row, uint8_t data);

private:
        uint8_t payFull[8] = {}; // init an empty array
};
#endif