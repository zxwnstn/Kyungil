#pragma once

typedef struct _Position{
	int x, y;

	_Position() {
		x = 0;
		y = 0;
	}

	_Position(int _x, int _y) {
		x = _x;
		y = _y;
	}

	_Position(const _Position& p) {
		x = p.x;
		y = p.y;
	}

	_Position& operator=(const _Position& p) {
		x = p.x;
		y = p.y;
		return *this;
	}

	void operator()(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void moveDown() {
		y += 1;
	}
	void moveLeft() {
		x -= 1;
	}
	void moveRight() {
		x += 1;
	}
	void moveUp() {
		y -= 1;
	}

}POSITION, *PPOSITION;

enum BlockShape {
	eImino,
	eOmino,
	eZmino,
	eSmino,
	eJmino,
	eLmino,
	eTmino
};

enum MY_INPUT {
	eNone,
	eUP,
	eDown,
	eLeft,
	eRight,
	eSpace,
	eStop,
	eSetDown
};