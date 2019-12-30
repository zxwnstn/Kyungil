#include "Board.h"
#include <stdlib.h>
#include <time.h>


void myBoard::shuffle()
{
	
	for (int i = 0; i < 500; ++i) {
		int toX = rand() % 4;
		int toY = rand() % 4;
		int fromX = rand() % 4;
		int fromY = rand() % 4;
		swap(board[toX][toY], board[fromX][fromY]);
	}
}

bool myBoard::safe(int nextX, int nextY)
{
	return ((0 <= nextX && nextX < 4) && (0 <= nextY && nextY < 4));
}

myBoard::myBoard()
{
	srand(time(NULL));

	int num = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			board[i][j] = num++;

	shuffle();

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] == 0) {
				curX = j;
				curY = i;
			}
		}
	}	
}

myBoard::~myBoard()
{
}

void myBoard::update(int _input)
{
	int nextX = curX;
	int	nextY = curY;
	bool moved = false;
	switch (_input){
	case 1:
		nextX--;
		if (safe(nextX, nextY)) {
			swap(board[curY][curX], board[nextY][nextX]);
			moved = true;
		}
		break;
	case 2:
		nextX++;
		if (safe(nextX, nextY)) {
			swap(board[curY][curX], board[nextY][nextX]);
			moved = true;
		}
		break;
	case 3:
		nextY--;
		if (safe(nextX, nextY)) {
			swap(board[curY][curX], board[nextY][nextX]);
			moved = true;
		}
		break;
	case 4:
		nextY++;
		if (safe(nextX, nextY)) {
			swap(board[curY][curX], board[nextY][nextX]);
			moved = true;
		}
		break;
	default:
		break;
	}
	if (moved) {
		curX = nextX;
		curY = nextY;
	}
}

void myBoard::render()
{
	system("cls");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] == 0)
				cout << "бр\t";
			else cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

bool myBoard::isEnd() {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i != 3 && j != 3) {
				if (board[i][j] != ++cnt)
					return false;
			}
		}
	}
	return true;
}
