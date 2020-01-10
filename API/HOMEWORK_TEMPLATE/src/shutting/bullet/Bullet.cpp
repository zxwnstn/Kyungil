#include "Bullet.h"

missile::missile()
{
	

}

missile::~missile()
{
	release();
}

HRESULT missile::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;
	for (int i = 0; i < bulletMax; ++i) {
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(bullet));
		bullet.bulletImage = new Image;
		bullet.bulletImage->init("images/missile.bmp", 26, 124, true, RGB(255, 0, 255));
		bullet.speed = 5.f;
		bullet.fire = false;
		_vBullet.push_back(bullet);
	}
	return E_NOTIMPL;
}

void missile::update()
{
	move();
}

void missile::render()
{
	_vBullet_iter = _vBullet.begin();
	for (_vBullet_iter; _vBullet_iter != _vBullet.end(); ++_vBullet_iter)
	{
		if (_vBullet_iter->fire == false) continue;
		_vBullet_iter->bulletImage->render(getMemDC(), _vBullet_iter->rc.left, _vBullet_iter->rc.top);

	}
}

void missile::release()
{
	for (int i = 0; i < _bulletMax; ++i) {
		SAFE_DELETE(_vBullet[i].bulletImage);
	}
}

void missile::move()
{
	_vBullet_iter = _vBullet.begin();
	for (_vBullet_iter; _vBullet_iter != _vBullet.end(); ++_vBullet_iter) {
		if (_vBullet_iter->fire == false)
			continue;
		_vBullet_iter->y -= _vBullet_iter->speed;

		_vBullet_iter->rc = RectMakeCenter(_vBullet_iter->x, _vBullet_iter->y,
			_vBullet_iter->bulletImage->getWidth(), _vBullet_iter->bulletImage->getHeight());

		if (_range < getDistance(_vBullet_iter->fireX, _vBullet_iter->fireY, _vBullet_iter->x, _vBullet_iter->y))
			_vBullet_iter->fire = false;

	}
}

void missile::fire(float x, float y)
{
	_vBullet_iter = _vBullet.begin();
	for (_vBullet_iter; _vBullet_iter != _vBullet.end(); ++_vBullet_iter)
	{
		if (_vBullet_iter->fire) continue;
		_vBullet_iter->fire = true;

		_vBullet_iter->x = _vBullet_iter->fireX = x;
		_vBullet_iter->y = _vBullet_iter->fireY = y;

		_vBullet_iter->rc = RectMakeCenter(_vBullet_iter->x, _vBullet_iter->y,
			_vBullet_iter->bulletImage->getWidth(), _vBullet_iter->bulletImage->getHeight());

		_vBullet_iter->bulletImage->render(getMemDC(), _vBullet_iter->rc.left, _vBullet_iter->rc.top);

		break;
	}
}

Nuclear::Nuclear()
{
}

Nuclear::~Nuclear()
{
}

HRESULT Nuclear::init(int bulletMax, float range)
{
	_range = range;
	_missileMax = bulletMax;
	_frameIdx = 0;
	return S_OK;
}

void Nuclear::release()
{
}

void Nuclear::update()
{
	move();
}

void Nuclear::render()
{
	for (_vBullet_iter = _vBullet.begin(); _vBullet_iter != _vBullet.end(); ++_vBullet_iter) {
		_vBullet_iter->bulletImage->frameRender(getMemDC(), _vBullet_iter->rc.left, _vBullet_iter->rc.bottom,
			_vBullet_iter->bulletImage->getFrameX(), _vBullet_iter->bulletImage->getMaxFrameY());

		_vBullet_iter->count++;

		if (_vBullet_iter->count % 10 == 0) {
			_frameIdx++;
			if (_frameIdx > _vBullet_iter->bulletImage->getMaxFrameX()) {
				_frameIdx = 0;
			}
			_vBullet_iter->bulletImage->setFrameX(_frameIdx);
		}
	}
}

void Nuclear::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new Image;
	bullet.bulletImage->init("../Common_Images/missile1.bmp", 0, 0, 416, 64, 13, 1, true, RGB(255, 0, 255));
	bullet.speed = 6.f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.bulletImage->getFrameWidth(), bullet.bulletImage->getFrameheight());

	_vBullet.push_back(bullet);
}

void Nuclear::move()
{
	for (_vBullet_iter = _vBullet.begin(); _vBullet_iter != _vBullet.end(); ) {
		_vBullet_iter->y -= _vBullet_iter->speed;
		_vBullet_iter->rc.bottom -= _vBullet_iter->speed;
		_vBullet_iter->rc.top -= _vBullet_iter->speed;

		if (_range < getDistance(_vBullet_iter->fireX, _vBullet_iter->fireY,
			_vBullet_iter->x + _vBullet_iter->bulletImage->getFrameWidth(),
			_vBullet_iter->y + _vBullet_iter->bulletImage->getFrameheight()
		))
		{
			_vBullet_iter = _vBullet.erase(_vBullet_iter);
		}
		else
		{
			_vBullet_iter++;
		}
	}
}
