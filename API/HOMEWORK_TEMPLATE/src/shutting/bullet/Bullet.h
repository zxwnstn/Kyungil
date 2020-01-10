#pragma once
#include "Game/gameNode.h"

struct tagBullet {
	Image* bulletImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float radius;
	float angle;
	float speed;
	bool fire;
	int count;
};

class Bullet{

public:
	Bullet();
	~Bullet();

};

class missile : public gameNode {
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _vBullet_iter;
	int _bulletMax;

public:
	missile();
	~missile();

	HRESULT init(int bulletMax, float range);
	void update();
	void render();
	void release();
	void move();
	void fire(float x, float y);
	float _range;

};

class Nuclear : public gameNode {
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _vBullet_iter;

	int _missileMax;
	float _range;
	float _frameIdx;

public:
	Nuclear();
	~Nuclear();

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);
	void move();

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getBullet() { return _vBullet_iter; }

};
