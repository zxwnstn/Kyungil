#include "func.h"

void setCursorPos(short x, short y, HANDLE _hConsole)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(_hConsole, pos);
}

void setCursorPos(const POSITION& _pos, HANDLE _hConsole)
{
	COORD pos = { _pos.x, _pos.y };
	SetConsoleCursorPosition(_hConsole, pos);
}

void setCursorPos(const COORD& _pos, HANDLE _hConsole)
{
	COORD pos = { _pos.X, _pos.Y };
	SetConsoleCursorPosition(_hConsole, pos);
}