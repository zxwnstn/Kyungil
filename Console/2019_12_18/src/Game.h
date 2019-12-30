#pragma once
#include "Board.h"


class Game {
private:
	myBoard* mBoard = nullptr;

public:
	Game();
	~Game();

private:
	int getInput();

public:
	int run();

};