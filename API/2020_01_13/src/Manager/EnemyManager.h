#pragma once
#include "Game/gameNode.h"
#include "shutting/bullet/Bullet.h"
#include "shutting/Enemy/Minion.h"


class EnemyManager 
	: public gameNode
{
private:
	typedef vector<class Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator EnemyIter;

private:
	vEnemy _vMinion;
	EnemyIter _vMinion_iter;
	Bullet* _bullet;


public:
	EnemyManager();
	~EnemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMinion();
	void minionBulletFire();
	
	EnemyIter getMinionIter() { return _vMinion_iter; }
	vEnemy& getMinion() { return _vMinion; }
	Bullet* getBullet() { return _bullet; }

};

