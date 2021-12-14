#ifndef __DEBUGGING_TOOLS_H__
#define __DEBUGGING_TOOLS_H__
#pragma once

#include <stdint.h>
#include <iostream>

#define DEBUG // status which can be used to debug files
#define SERIAL_MODE true

void DebuggerPrintSimple(std::string txt);
void DebuggerPrintPayloadInfo(const uint8_t pl[8]);

#endif // __DEBUGGING_TOOLS_H__