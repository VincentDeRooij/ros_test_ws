#ifndef MBOXDRIVESETTINGS_H
#define MBOXDRIVESETTINGS_H

#include "Mailbox.h"
#include "ExROutput.h"

#pragma once

class MBoxDriveSettings : public Mailbox, ExROutput<ExRDataStructureTypeUInt>
{
private:
	bool engineIsEnabled = false;

public:
	MBoxDriveSettings(const bool &engineEnabled);
	~MBoxDriveSettings();

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read() override;
	virtual Payload Write() override;
};
#endif