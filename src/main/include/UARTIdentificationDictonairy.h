#ifndef UARTIDENTIFICATIONDICTONAIRY_H
#define UARTIDENTIFICATIONDICTONAIRY_H
#pragma once

// system includes
#include <stdint.h>
#include <map>

// created includes
#include "exr_definitions.h"
#include "payload.h"

//A class with all the UART messages defined, ready to sent when you call them. 
class UARTIdentificationDictonairy  
{
	private:
	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
		std::map<uint16_t, Payload> m = // sample for getting the motherboard information
		{
			{EX_MOTHER_PORT_OUTPUT_SET_TYPE, Payload()}
		};

	public:
	UARTIdentificationDictonairy() = default;
	~UARTIdentificationDictonairy() = default;
};
#endif