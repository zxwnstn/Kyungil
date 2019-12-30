#pragma once
#include "MapLoader.h"
#include "GameMap.h"

class mainGame
{
private:
	MapLoader* mapLoader;
	GameMap* map;
	int input;

private:
	void getInput(int);

public:
	mainGame();
	~mainGame();

	void init(int);
	void run(int);
};

