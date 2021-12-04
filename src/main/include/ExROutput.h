#ifndef EXROUTPUT_H
#define EXROUTPUT_H
#pragma once

#include <string>

class ExROutput
{
private:
public:
	ExROutput(std::string type)
	{
		this->type = type;
	}
	virtual ~ExROutput() = default;

	std::string GetType()
	{
		return this->type;
	}

protected:
	std::string type;
};
#endif