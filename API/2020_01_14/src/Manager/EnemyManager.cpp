#include "Etc/stdafx.h"
#include "EnemyManager.h"



EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	this->setMinion();

	_bullet = new Bullet;
	_bullet->init("bullet", 10, 600);
	return S_OK;
}

void EnemyManager::release()
{
	SAFE_DELETE(_bullet);
}

void EnemyManager::update()
{
	_vMinion_iter = _vMinion.begin();
	for (_vMinion_iter; _vMinion_iter != _vMinion.end(); _vMinion_iter++) {
		(*_vMinion_iter)->update();
	}
	_bullet->update();

	this->minionBulletFire();
}

void EnemyManager::render()
{
	_vMinion_iter = _vMinion.begin();
	for (_vMinion_iter; _vMinion_iter != _vMinion.end(); _vMinion_iter++) {
		(*_vMinion_iter)->render();
	}
	_bullet->render();
}

void EnemyManager::setMinion()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 1; ++j) {
			Enemy* ufo = new Minion;
			ufo->init("ufo", PointMake(100 + i * 200, 100 + j * 150 ));
			_vMinion.push_back(ufo);
		}
	}
}

void EnemyManager::minionBulletFire()
{
	_vMinion_iter = _vMinion.begin();
	for (_vMinion_iter; _vMinion_iter != _vMinion.end(); _vMinion_iter++) {
		if ((*_vMinion_iter)->bulletcountFrire()) {
			RECT rc = (*_vMinion_iter)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + 30, PI / 2, 5.f);
		}
	}
}
