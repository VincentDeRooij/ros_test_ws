#ifndef MBOXBANDWIDTH_H
#define MBOXBANDWIDTH_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Mailbox Write Interface
#include "IMBoxWrite.h"

class MBoxBandWidth : public Mailbox, public IMBoxWrite
{
private:
public:
	MBoxBandWidth();
	~MBoxBandWidth() = default;

	virtual Payload Write() override;
};
#endif