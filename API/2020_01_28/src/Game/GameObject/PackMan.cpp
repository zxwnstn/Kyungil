#include "PackMan.h"



PackMan::PackMan()
{
}


PackMan::~PackMan()
{
}

bool PackMan::init()
{
	image = IMAGEMANAGER->findImage("ÆÑ¸Ç");
	collisionRect = UTIL::IRectMakeCenter(70, 70, 30, 32);

	return true;
}

void PackMan::update(float _deltaTime)
{
	changePastTime += _deltaTime;
	if (changePastTime > changeDelay) {
		changePastTime = 0;
		if (imageIdxX) imageIdxX = 0;
		else imageIdxX = 1;
	}

	if (KEYMANAGER->isStayKeyDown(P1_UP)) state = PackManDir::eUp;
	else if (KEYMANAGER->isStayKeyDown(P1_DOWN)) state = PackManDir::eDown;
	else if (KEYMANAGER->isStayKeyDown(P1_LEFT)) state = PackManDir::eLeft;
	else if (KEYMANAGER->isStayKeyDown(P1_RIGHT)) state = PackManDir::eRight;

	switch (state)
	{
	case PackManDir::eUp:
		collisionRect.moveUp(speed);
		if (!UTIL::isRectColorSame(IMAGEMANAGER->findImage("¸Ê")->getMemDC(), collisionRect, 2, 2))
			collisionRect.moveDown(speed);
		break;
	case PackManDir::eDown:
		collisionRect.moveDown(speed);
		if (!UTIL::isRectColorSame(IMAGEMANAGER->findImage("¸Ê")->getMemDC(), collisionRect, 2, 2))
			collisionRect.moveUp(speed);
		break;
	case PackManDir::eLeft:
		collisionRect.moveLeft(speed);
		if (!UTIL::isRectColorSame(IMAGEMANAGER->findImage("¸Ê")->getMemDC(), collisionRect, 2, 2))
			collisionRect.moveRight(speed);
		break;
	case PackManDir::eRight:
		collisionRect.moveRight(speed);
		if (!UTIL::isRectColorSame(IMAGEMANAGER->findImage("¸Ê")->getMemDC(), collisionRect, 2, 2))
			collisionRect.moveLeft(speed);
		break;
	}
}

void PackMan::render(HDC hdc)
{
	switch (state)
	{
	case PackManDir::eUp:
		image->frameRender(hdc, collisionRect.left, collisionRect.top, imageIdxX, 2);
		break;
	case PackManDir::eDown:
		image->frameRender(hdc, collisionRect.left, collisionRect.top, imageIdxX, 3);
		break;
	case PackManDir::eLeft:
		image->frameRender(hdc, collisionRect.left, collisionRect.top, imageIdxX, 1);
		break;
	case PackManDir::eRight:
		image->frameRender(hdc, collisionRect.left, collisionRect.top, imageIdxX, 0);
		break;
	}	
}

void PackMan::afterRender(HDC hdc)
{
}

void PackMan::debugRender(HDC hdc)
{
	UTIL::DrawColorRect(hdc, collisionRect, RGB(0, 255, 0));
}
