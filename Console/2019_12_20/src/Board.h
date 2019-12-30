#pragma once
#include "Shop.h"
#include "Character.h"
#include "Inventory.h"
#include "type.h"

class Board
{
private:
	Shop*		mShop;
	Character*	mPlayer;
	Inventory*	mInventory;	

private:
	int			curX;
	int			curY;
	bool		gameEnd;
	int			mapArr[10][10]			
	{
		{2, 2, 2, 2, 0, 2, 2, 2, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 0, 2, 0},
		{0, 0, 0, 0, 0, 2, 0, 0, 2, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 2, 2, 0, 2, 2, 2, 2, 0, 2},
		{0, 2, 0, 0, 2, 3, 1, 2, 0, 0},
		{0, 2, 0, 2, 2, 2, 0, 0, 0, 0}
	};

private:
	bool isMovable(int, int);
	void endConfirm();

public:
	void update(Input);
	void render();
	void init();
	bool isEnd();

public:
	Board();
	~Board();
};

