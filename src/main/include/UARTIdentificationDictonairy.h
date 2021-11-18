#ifndef UARTIDENTIFICATIONDICTONAIRY_H
#define UARTIDENTIFICATIONDICTONAIRY_H
#pragma once

#include <stdint.h>
#include <exr_definitions.h>
#include <payload.h>
	
class UARTIdentificationDictonairy  
{
	private:
	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
			 std::map<uint16_t, uint8_t[8]> m ={
				{EX_MOTHER_PORT_OUTPUT_SET_TYPE, Payload('', '', '', '', '', '', '', '')},
				{}




			 };
	public:

		UARTIdentificationDictonairy();
		~UARTIdentificationDictonairy();

};
#endif