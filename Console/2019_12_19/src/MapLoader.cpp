#include "MapLoader.h"
#include <iostream>
#include <string.h>
#include <Windows.h>

MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}

void MapLoader::init(GameMap* src)
{
	(*this)(src, 0);
}

void MapLoader::operator()(GameMap* src, int mapIdx)
{
	using namespace std;

	char mapName[20];
	strcpy(mapName, mapNameList[mapIdx]);

	char tempBuff[MAXIMUM_HEIGHT][MAXIMUM_WIDTH];
	char mapPath[100] = ".\\map\\";
	strcat(mapPath, mapName);

	FILE* fp = fopen(mapPath, "r");
	
	int cnt = 0;
	while (fgets(tempBuff[cnt], MAXIMUM_WIDTH, fp) != nullptr) {
		printf("%s", tempBuff[cnt++]);
	}

	src->init(tempBuff);
	src->newMapSet();
}
