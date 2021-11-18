#ifndef UARTIDENTIFICATIONDICTONAIRY_H
#define UARTIDENTIFICATIONDICTONAIRY_H
#pragma once

#include <stdint.h>
#include <exr_definitions.h>
#include <map>
	
class UARTIdentificationDictonairy  
{
	private:
	//In the map m you'll find the BITDATA that alligns with the Serial adress that's given.
			 std::map<uint16_t, Payload> m ={
				{EX_MOTHER_PORT_OUTPUT_SET_TYPE, Payload()}
			 };

	public:



};
#endif