#pragma once
#include "GameMap.h"

class MapLoader
{
	char mapNameList[5][20] = { "village1.txt", "village2.txt", "BossRoom.txt", "village3.txt", "village4.txt" };

public:
	MapLoader();
	~MapLoader();

	void init(GameMap*);
	void operator()(GameMap*, int);

};

