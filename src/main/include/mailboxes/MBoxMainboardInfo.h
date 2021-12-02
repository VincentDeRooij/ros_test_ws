#ifndef MAINBOARDINFO_H
#define MAINBOARDINFO_H

#include "Mailbox.h"

#pragma once

class MBoxMainboardInfo : public Mailbox
{
private:
public:
	MBoxMainboardInfo();
	~MBoxMainboardInfo();

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read();
	virtual void Write();
};
#endif