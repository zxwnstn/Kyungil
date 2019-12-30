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
	POSITION m_posArr[4]; //��ġ����, pos[0]�� ���̽��� �ȴ�.
	int shapeType; // 1-�� 2-�� 3-����(T�̳�) 4-9��(T�̳�)
	BlockShape blockShape;

public:
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveRotate();
};

