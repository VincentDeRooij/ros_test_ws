#ifndef MBOXSPEEDREF_H
#define MBOXSPEEDREF_H
#pragma once

// Mailbox class
#include "Mailbox.h"

// Mailbox Write Interface
#include "IMBoxWrite.h"

// Converter
#include "Converter.h"

class MBoxSpeedRef : public Mailbox, public IMBoxWrite
{
private:
	int8_t right;
	int8_t left;

public:
	MBoxSpeedRef(int8_t right, int8_t left);
	~MBoxSpeedRef() = default;

	virtual Payload Write() override;
};
#endif