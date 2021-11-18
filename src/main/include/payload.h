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

        uint8_t pl_full[8];
	public:
        Payload();
        Payload* getPayloadFull();
        int getPayloadRow(int row);
        void setPayloadRow(int row, uint8_t data);
        replacePayload(Payload Payload);
};
#endif