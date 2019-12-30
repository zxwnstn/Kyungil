#include "GameMap.h"
#include <stdlib.h>
#include <iostream>

int GameMap::isRange(int dx, int dy)
{
	int nextX = curX + dx;
	int nextY = curY + dy;
	int next = map[nextY][nextX];
	if (next == ' ')
		return 1;
	else if (next == '#')
		return 2;
	else return 3;
}

GameMap::GameMap()
{
}


GameMap::~GameMap()
{
}

void GameMap::newMapSet()
{
	newMap = false;
}

void GameMap::init(char(&_map)[MAXIMUM_HEIGHT][MAXIMUM_WIDTH])
{
	//map이름 세팅
	for (int i = 0; i < MAXIMUM_WIDTH; ++i) {
		if (_map[0][i] != '\n')
			mapName[i] = _map[0][i];
		else {
			mapName[i] = 0;
			break;
		}
	}

	//가로 세로 정보 세팅
	char strWidth[10];
	char strHeight[10];
	int endWidhth;
	for (int i = 0; i < MAXIMUM_WIDTH; ++i) {
		if (_map[1][i] != ' ')
			strWidth[i] = _map[1][i];
		else {
			endWidhth = i;
			strWidth[i] = 0;
			break;
		}
	}
	int cnt = 0;
	for (int i = endWidhth + 1; i < MAXIMUM_WIDTH; ++i) {
		if (_map[1][i] != '\0')
			strHeight[cnt++] = _map[1][i];
		else {
			strHeight[cnt] = 0;
			break;
		}
	}
	map_height = atoi(strHeight);
	map_width = atoi(strWidth);

	//맵 세팅
	for (int i = 2; i < map_height + 2; ++i)
		for (int j = 0; j < map_width; ++j)
			map[i - 2][j] = _map[i][j];

	//플레이어 위치세팅
	calcCurPos();
}

void GameMap::swapPos(int nextX, int nextY) {
	if (map[nextY][nextX] == ' ') {
		curX = nextX;
		curY = nextY;
	}
	else if (map[nextY][nextX] == '#') {}
	else {
		newMap = true;
		newMapInfo = map[nextY][nextX];
	}
}

void GameMap::calcCurPos()
{
	if (prevInputKey == 0) {
		curX = 1;
		curY = 4;
		return;
	}
	switch (prevInputKey){
	case 8:
		curX = prevMapX;
		curY = map_height - 2;
		break;
	case 2:
		curY = 1;
		curX = prevMapX;
		break;
	case 4:
		curY = prevMapY;
		curX = map_width - 2;
		break;
	case 6:
		curY = prevMapY;
		curX = 1;
		break;
	}
}

void GameMap::update(int _input)
{
	int result;
	int nextX = curX;
	int	nextY = curY;
	switch (_input)
	{
	case 8:
		nextY--;
		break;
	case 4:
		nextX--;
		break;
	case 2:
		nextY++;
		break;
	case 6:
		nextX++;
		break;
	default:
		break;
	}
	swapPos(nextX, nextY);
	prevInputKey = _input;
}

void GameMap::render()
{
	for (int i = 0; i < map_height; ++i) {
		for (int j = 0; j < map_width; ++j) {
			if (i == curY && j == curX)
				std::cout << '0';
			else if ('a' <= map[i][j] && map[i][j] <= 'z')
				std::cout << " ";
			else std::cout << map[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "==== " << mapName << " ====";
}

int GameMap::mapChange()
{
	if (newMap) {
		prevMapX = curX;
		prevMapY = curY;
		return newMapInfo - 'a';
	}
	else
		return -1;
}
