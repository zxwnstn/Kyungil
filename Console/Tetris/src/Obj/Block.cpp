#include "Block.h"

Block::Block()
{
	blockShape = static_cast<BlockShape>(rand() % 7);
	//blockShape = eJmino;

	m_posArr[0] = POSITION(4, 1);
	int posBx = m_posArr[0].x;
	int posBy = m_posArr[0].y;
	shapeType = 1;

	switch (blockShape)
	{	
	case eImino:	
		m_posArr[1](posBx, posBy - 1);
		m_posArr[2](posBx, posBy + 1);
		m_posArr[3](posBx, posBy + 2);
		break;
	case eOmino:
		m_posArr[1](posBx, posBy - 1);
		m_posArr[2](posBx + 1, posBy - 1);
		m_posArr[3](posBx + 1, posBy);
		break;
	case eZmino:
		m_posArr[1](posBx -1, posBy - 1);
		m_posArr[2](posBx, posBy - 1);
		m_posArr[3](posBx + 1, posBy);
		break;
	case eSmino:
		m_posArr[1](posBx, posBy - 1);
		m_posArr[2](posBx + 1, posBy - 1);
		m_posArr[3](posBx - 1, posBy);
		break;
	case eJmino:
		m_posArr[1](posBx - 1, posBy - 1);
		m_posArr[2](posBx - 1, posBy);
		m_posArr[3](posBx + 1, posBy);
		break;
	case eLmino:
		m_posArr[1](posBx + 1, posBy - 1);
		m_posArr[2](posBx - 1, posBy);
		m_posArr[3](posBx + 1, posBy);
		break;
	case eTmino:
		m_posArr[1](posBx, posBy - 1);
		m_posArr[2](posBx - 1, posBy);
		m_posArr[3](posBx + 1, posBy);
		break;
	default:
		break;
	}
}


Block::~Block()
{
}

void Block::rotate_point(const POSITION& _base, POSITION& _src)
{
	//x가 같을 경우

	if (_src.x == _base.x) {
		_src.x = _base.x + (_base.y - _src.y);
		_src.y = _base.y;
		return;
	}
	//y가 같을 경우
	if (_src.y == _base.y) {
		_src.y = _base.y - (_base.x - _src.x);
		_src.x = _base.x;
		return;
	}

	int tempSrcX = _src.x - _base.x;
	int tempSrcY = _src.y - _base.y;
	//12~3
	if (tempSrcX > 0 && tempSrcY < 0) {
		_src.x = -tempSrcY + _base.x;
		_src.y = tempSrcX + _base.y;
		return;
	}
	//3~6
	if (tempSrcX > 0 && tempSrcY > 0) {
		_src.x = -tempSrcY + _base.x;
		_src.y = tempSrcX + _base.y;
		return;
	}
	//6~9
	if (tempSrcX < 0 && tempSrcY > 0) {
		_src.x = -tempSrcY + _base.x;
		_src.y = tempSrcX + _base.y;
		return;
	}
	//9~12
	if (tempSrcX < 0 && tempSrcY < 0) {
		_src.x = -tempSrcY + _base.x;
		_src.y = tempSrcX + _base.y;
		return;
	}
}


void Block::moveDown()
{
	for (int i = 0; i < 4; ++i) 
		m_posArr[i].moveDown();
}

void Block::moveLeft()
{
	for (int i = 0; i < 4; ++i)
		m_posArr[i].moveLeft();
}

void Block::moveRight()
{
	for (int i = 0; i < 4; ++i)
		m_posArr[i].moveRight();
}

void Block::moveUp()
{
	for (int i = 0; i < 4; ++i)
		m_posArr[i].moveUp();
}

void Block::rotate() {
	if (shapeType == 1) {
		for (int i = 1; i <= 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				rotate_point(m_posArr[0], m_posArr[i]);
			}
		}
		shapeType = 2;
	}
	else if (shapeType == 2) {
		for (int i = 1; i <= 3; ++i)
			rotate_point(m_posArr[0], m_posArr[i]);
		shapeType = 1;
	}
}

void Block::rotateT()
{
	if (shapeType == 1) {
		for (int i = 1; i <= 3; ++i)
			rotate_point(m_posArr[0], m_posArr[i]);
		shapeType = 2;
	}
	else if (shapeType == 2) {
		for (int i = 1; i <= 3; ++i)
			rotate_point(m_posArr[0], m_posArr[i]);
		shapeType = 3;
	}
	else if (shapeType == 3) {
		for (int i = 1; i <= 3; ++i)
			rotate_point(m_posArr[0], m_posArr[i]);
		shapeType = 4;
	}
	else if (shapeType == 4) {
		for (int i = 1; i <= 3; ++i)
			rotate_point(m_posArr[0], m_posArr[i]);
		shapeType = 1;
	}
}

void Block::moveRotate()
{
	switch (blockShape)
	{
	case eOmino:
		break;
	case eTmino:
		rotateT();
		break;
	case eJmino:
		rotateT();
		break;
	case eLmino:
		rotateT();
		break;	
	default:
		rotate();
		break;
	}
}

