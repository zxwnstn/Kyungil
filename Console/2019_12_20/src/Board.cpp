#include "Board.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

void Board::init()
{
	mShop = new Shop;
	mShop->init();
	mPlayer = new Character(1000000);
	mInventory = new Inventory;
	mInventory->init(mPlayer);
	gameEnd = false;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (mapArr[i][j] == 1) {
				curX = j;
				curY = i;
			}
		}
	}
}

bool Board::isEnd()
{
	return gameEnd;
}

bool Board::isMovable(int x, int y)
{
	if ((0 <= x && x < 10) && (0 <= y && y < 10))
		if (mapArr[y][x] == 0)
			return true;
	return false;
}

void Board::endConfirm()
{
	char tpInput;
	printf("정말로 게임을 종료하시겟습니까?? y/n ");
	std::cin >> tpInput;
	if (tpInput == 'Y' || tpInput == 'y') {
		gameEnd = true;
		Sleep(1000);
	}
}


void Board::update(Input _input)
{
	int nextX = curX;
	int nextY = curY;
	switch (_input){
	case eUp:
		nextY--;
		break;
	case eDown:
		nextY++;
		break;
	case eLeft:
		nextX--;
		break;
	case eRight:
		nextX++;
		break;
	case eInventory:
		mInventory->run();
		break;
	case eCharacror:
		mPlayer->run();
		break;
	case eExit:
		endConfirm();
		return;
	case eNone:
		return;
	}
	if (isMovable(nextX, nextY)) {
		std::swap(mapArr[curY][curX], mapArr[nextY][nextX]);
		curY = nextY;
		curX = nextX;
	}
	else if (mapArr[nextY][nextX] == 3) {
		mShop->run(mPlayer);
	}
}

void Board::render()
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (mapArr[i][j] == 0) 
				printf("  ");
			if (mapArr[i][j] == 1)
				printf("★");
			if (mapArr[i][j] == 2)
				printf("▩");
			if (mapArr[i][j] == 3)
				printf("▣");		
		}
		printf("\n");
	}
}

Board::Board()
{
}


Board::~Board()
{
	delete mShop;
	delete mPlayer;
	delete mInventory;
}