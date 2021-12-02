#ifndef DRIVESETTINGS_H
#define DRIVESETTINGS_H

#include "Mailbox.h"

#pragma once

class MBoxDriveSettings : public Mailbox
{
private:
public:
	MBoxDriveSettings();
	~MBoxDriveSettings();

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read();
	virtual void Write();
};
#endif