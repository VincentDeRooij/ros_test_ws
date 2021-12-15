#ifndef MBOXSPEEDREF_H
#define MBOXSPEEDREF_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Converter
#include "Converter.h"

class MBoxSpeedRef : public Mailbox
{
private:
	int8_t right;
	int8_t left;

public:
	MBoxSpeedRef(int8_t right, int8_t left);
	~MBoxSpeedRef() = default;

	Payload Write() override;
	void Read(Payload &p) override;
};
#endif