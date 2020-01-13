#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
	return S_OK;
}

HRESULT Enemy::init(const char * imageName, POINT position)
{
	_count = 0;
	_currentFrameX = 0;
	_currentFrameY = 0;

	_fireCount = 0;
	_rndFireCount = RND->getFromIntTo(1, 1000);

	_img = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _img->getFrameWidth(), _img->getFrameheight());


	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	animation();
}

void Enemy::render()
{
	draw();
}

void Enemy::draw()
{
	_img->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

void Enemy::animation()
{
	_count++;
	if (_count % 3 == 0) {
		_img->setFrameX(_img->getFrameX() + 1);
		_currentFrameX++;
			
		if (_currentFrameX > _img->getMaxFrameX()) {
			_currentFrameX = 0;
		}
	}
}

bool Enemy::bulletcountFrire()
{
	_fireCount++;
	if (_fireCount % _rndFireCount == 0) {
		_rndFireCount = RND->getFromIntTo(1, 1000);
		_fireCount = 0;
		return true;
	}
	return false;
}
