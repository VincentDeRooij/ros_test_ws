#ifndef CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#define CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#pragma once

// system includes
#include <stdint.h>
#include <map>

// created includes
#include "exr_definitions.h"

class ControllerIdentificationDictionairy  
{
	private:
		std::map<, unint16_t> m = // sample for getting the motherboard information
		{
			{, EX_MOTHER_PORT_OUTPUT_SET_TYPE}
		};
	public:

		ControllerIdentificationDictionairy();
		~ControllerIdentificationDictionairy();

};
#endif