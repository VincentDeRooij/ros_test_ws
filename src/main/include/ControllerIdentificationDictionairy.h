#ifndef CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#define CONTROLLERIDENTIFICATIONDICTIONAIRY_H
#pragma once

// system includes
#include <stdint.h>
#include <map>

// created includes
#include "ExRSerialDefinitions.h"
#include "ButtonDefinitions.h"

class ControllerIdentificationDictionairy
{
private:
	std::map<uint16_t, uint16_t> m = // sample for getting the motherboard information
		{
			{X, EX_MAINBOARD_OUTPUTSETTINGS_TYPE_SET} //DEFINITION FOR X BUTTON
	};

public:
	ControllerIdentificationDictionairy();
	~ControllerIdentificationDictionairy();
};
#endif

//<<< REMOVE TAG:
// CONTROLLER input -A-> ROS_MOTOR_TX2 <while ROS_CONTROL> <--0x200/CMD--> ROS_MOTOR_INTL --> SERIAL --> MOTOR

// sw() :

// 	   case : break;

// [1 1 0 0 0 0 0 0 0 0 0] =
// [0 1 0 0 0 0 0 0 0 0 0] =