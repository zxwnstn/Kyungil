#pragma once
#include "Game/gameNode.h"

class Enemy : public gameNode
{
private:
	Image* _img;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;
	int _count;

	int _fireCount;
	int _rndFireCount;

public:
	Enemy();
	~Enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	virtual void draw();
	virtual void animation();

	bool bulletcountFrire();
	RECT getRect() { return _rc; }
};

