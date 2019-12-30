#pragma once
#include <Windows.h>
#include "type.h"

void setCursorPos(short x, short y, HANDLE _hConsole);
void setCursorPos(const POSITION& _pos, HANDLE _hConsole);
void setCursorPos(const COORD& _pos, HANDLE _hConsole);