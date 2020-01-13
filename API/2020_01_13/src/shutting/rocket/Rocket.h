#pragma once
#include "Game/gameNode.h"
#include "shutting/bullet/Bullet.h"

#define PLAYERSPEED 5

class Rocket :public gameNode{
	
	Image* _player;
	missile* _missile;
	Nuclear* _nuclear;
	RECT rc;
	int rocketHp = 30;

public:
	Rocket();
	~Rocket();

	HRESULT init();
	void update();
	void render();
	void release();

	Nuclear* getNuclear() { return _nuclear; }
	RECT& getRect() { return rc; }
	void decRocketHp() { if(rocketHp > 0) rocketHp -= 10; }
	int getRocketHp() { return rocketHp; }
};