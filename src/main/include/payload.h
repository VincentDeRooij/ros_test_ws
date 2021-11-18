#ifndef PAYLOAD_H
#define PAYLOAD_H
#pragma once

#include <stdint.h>
#include <exr_definitions.h>
	
class Payload
{
	private:
        uint8_t pl_0;
        uint8_t pl_1;
        uint8_t pl_2;
        uint8_t pl_3;
        uint8_t pl_4;
        uint8_t pl_5;
        uint8_t pl_6;
        uint8_t pl_7;

        uint8_t pl_full[8] = {}; // init an empty array
	public:
        Payload() = default;
        Payload(uint8_t pay_0, uint8_t pay_1, uint8_t pay_2, uint8_t pay_3, uint8_t pay_4, uint8_t pay_5, uint8_t pay_6, uint8_t pay_7);
        uint8_t* getPayloadFull();
        void combinePayload();
        uint8_t getPayloadRow(int row);
        void setPayloadRow(int row, uint8_t data);
};
#endif