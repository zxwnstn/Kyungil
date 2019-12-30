#pragma once
#include <iostream>
using namespace std;

class myBoard {
private:
	int board[4][4];
	int curX, curY;

private:
	void shuffle();
	bool safe(int, int);

public:
	myBoard();
	~myBoard();
	
	void update(int);
	void render();
	bool isEnd();
};
