#ifndef __SERIALVALIDATORS_H__
#define __SERIALVALIDATORS_H__
#pragma once

// system includes

// created includes
#include "ExRMsgStructures.h"

bool ValidateHeaders(ExRMessage &receivedMsg);
bool CalcCRCFromExRMessage(ExRMessage &msg);

#endif // __SERIALVALIDATORS_H__