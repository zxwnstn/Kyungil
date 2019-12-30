#pragma once
#include "../etc/Game.h"

class Block{
public:
	Block();
	~Block();

private:
	void rotate_point(const POSITION&, POSITION&);
	void rotate();
	void rotateT();

public:
	POSITION m_posArr[4]; //위치정보, pos[0]이 베이스가 된다.
	int shapeType; // 1-정 2-반 3-세시(T미노) 4-9시(T미노)
	BlockShape blockShape;

public:
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveRotate();
};

