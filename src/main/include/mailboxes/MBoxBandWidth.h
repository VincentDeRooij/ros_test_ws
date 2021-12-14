#ifndef MBOXBANDWIDTH_H
#define MBOXBANDWIDTH_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Mailbox Write Interface
#include "IMBoxWrite.h"

class MBoxBandWidth : public Mailbox
{
private:
public:
	MBoxBandWidth();
	~MBoxBandWidth() = default;

	Payload Write();
	void Read(Payload &p);
};
#endif