#ifndef MBOXMAINBOARDINFO_H
#define MBOXMAINBOARDINFO_H

#include "Mailbox.h"
#include "ExROutput.h"

#pragma once

//template <typename OutType>
class MBoxMainboardInfo : public Mailbox, ExROutput<ExRDataStructureTypeUInt>
{
private:
	//OutType *oType;

	bool lightIOPortOneIsEnabled = false;
	bool lightIOPortTwoIsEnabled = false;
	bool engineIOPortIsEnabled = false;

public:
	MBoxMainboardInfo(const bool &lightIOPortOne, const bool &lightIOPortTwo, const bool &engineIOPort);
	~MBoxMainboardInfo();

	// inherit the method from mailbox, allowing our own method implementations
	virtual void Read();
	virtual Payload Write() override;
};
#endif