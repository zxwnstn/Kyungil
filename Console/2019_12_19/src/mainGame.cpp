#include "mainGame.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


void mainGame::getInput(int inputMode)
{
	if (inputMode == 1) {
		std::cin >> input;
	}
	else {
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				switch (c)
				{
				case 75:
					input = 4;
					return;
				case 77:
					input = 6;
					return;
				case 72:
					input = 8;
					return;
				case 80:
					input = 2;
					return;
				}
			}
		}
		input = 0;
	}
}

void mainGame::init(int inputMode)
{
	map = new GameMap;
	mapLoader = new MapLoader;
	mapLoader->init(map);
	if (inputMode == 0) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cCursor;
		cCursor.bVisible = 0;
		cCursor.dwSize = 1;
		SetConsoleCursorInfo(hConsole, &cCursor);
	}

}

void mainGame::run(int inputMode)
{
	while (1) {
		system("cls");
		map->render();
		getInput(inputMode);
		map->update(input);
		if (map->mapChange() >= 0)
			(*mapLoader)(map, map->mapChange());
	}
}
