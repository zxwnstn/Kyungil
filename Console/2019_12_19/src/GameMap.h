#pragma once
#define MAXIMUM_WIDTH 200
#define MAXIMUM_HEIGHT 200

class GameMap{

private:
	char map[MAXIMUM_HEIGHT][MAXIMUM_WIDTH];
	char mapName[20];
	int map_width, map_height;
	int curX, curY;

//for next map
private: 
	int prevMapX;
	int prevMapY;
	bool newMap = false;
	char newMapInfo;
	int prevInputKey = 0;

private:
	int isRange(int, int ); // 1 - ºó°ø°£,  2 - Àå¾Ö¹°,  'a', 'b', 'c' - ´ÙÀ½¸Ê
	void swapPos(int, int);
	void calcCurPos();

public:
	GameMap();
	~GameMap();

public:
	void newMapSet();
	int mapChange();

	void init(char (&_map)[MAXIMUM_HEIGHT][MAXIMUM_WIDTH]);
	void update(int);
	void render();
};

