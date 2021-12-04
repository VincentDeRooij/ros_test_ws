#ifndef MBOXDRIVESETTINGS_H
#define MBOXDRIVESETTINGS_H

#include "Mailbox.h"

#pragma once

class MBoxDriveSettings : public Mailbox
{
private:
public:
	MBoxDriveSettings();
	~MBoxDriveSettings();

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read() override;
	virtual void Write() override;
};
#endif