#ifndef EXROUTPUT_H
#define EXROUTPUT_H
#pragma once

#include <string>
#include "ExROutputStructures.h"

template <typename OutType>
class ExROutput
{
public:
	ExROutput() = default;
	virtual ~ExROutput() = default;

protected:
	OutType *oType; // the type of output structure given
};
#endif