#include "Game.h"
#include <conio.h>
Game::Game()
{
	mBoard = new myBoard;
}

Game::~Game()
{
	delete mBoard;
}

int Game::getInput()
{
	char c;
	if (_kbhit()) {
		c = _getch();
		if (c == -32) {
			c = _getch();
			switch (c)
			{
			case 75:
				return 2;
			case 77:
				return 1;
			case 72:
				return 4;
			case 80:
				return 3;
			default:
				return 0;
			}
		}
	}
	return 0;
}

int Game::run()
{
	while (!mBoard->isEnd()) {
		mBoard->update(getInput());
		mBoard->render();
	}
	return 1;
}
