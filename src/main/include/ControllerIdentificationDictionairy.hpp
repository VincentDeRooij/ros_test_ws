#ifndef CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#define CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#pragma once

// system includes
#include <stdint.h>
#include <map>

// created includes
#include "exr_definitions.h"
#include "button_definitions.h"

class ControllerIdentificationDictionairy  
{
	private:
		std::map<uint16_t, unint16_t> m = // sample for getting the motherboard information
		{
			{X, EX_MOTHER_PORT_OUTPUT_SET_TYPE} //DEFINITION FOR X BUTTON
		};
	public:

		ControllerIdentificationDictionairy();
		~ControllerIdentificationDictionairy();

};
#endif