#pragma once
#include "Common/gameNode.h"
#include "shutting/bullet/Bullet.h"

#define PLAYERSPEED 5

class Rocket :public gameNode{
	
	Image* _player;
	missile* _missile;
	Nuclear* _nuclear;
	RECT rc;

public:
	Rocket();
	~Rocket();

	HRESULT init();
	void update();
	void render();
	void release();

};