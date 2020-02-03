#include "stdafx.h"
#include "camel.h"
#include "SystemManager/AnimationManager.h"

camel::camel()
{
}

camel::~camel()
{
}

bool camel::init()
{
	_camel = IMAGEMANAGER->addFrameImage("camel", "../Common_Images/camel.bmp", 300, 267,4,3, true, RGB(255, 0, 255));

	int arrlen[] = { 1,2,3,7,8 };
	ANIMANAGER->addDefAnimation("ani1", "camel", 10, true, true);
	ANIMANAGER->addAnimation("ani2", "camel", arrlen, 5, 5, true);
	ANIMANAGER->addAnimation("ani3", "camel",0, 5,10, false, true);


	_ani = ANIMANAGER->findAnimation("ani1");

	return S_OK;
}

void camel::update(float _deltaTime)
{
	if(KEYMANAGER->isOnceKeyDown(P1_UP))
	{
		if (_ani == ANIMANAGER->findAnimation("ani1")) {
			if (_ani->isPlay())
				_ani->pause();
			else {
				_ani->resume();
			}
		}
		else {
			_ani = ANIMANAGER->findAnimation("ani1");
			ANIMANAGER->start("ani1");
		}
	}
	if (KEYMANAGER->isOnceKeyDown(P1_LEFT))
	{
		if (_ani == ANIMANAGER->findAnimation("ani2")) {
			if (_ani->isPlay())
				_ani->pause();
			else {
				_ani->resume();
			}
		}
		else {
			_ani = ANIMANAGER->findAnimation("ani2");
			ANIMANAGER->start("ani2");
			_ani->setFPS(15);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(P1_RIGHT))
	{
		if (_ani == ANIMANAGER->findAnimation("ani3")) {
			if (_ani->isPlay()) {
				_ani->pause();
			}
			else {
				_ani->resume();
			}
		}
		else {
			_ani = ANIMANAGER->findAnimation("ani3");
			ANIMANAGER->start("ani3");
			_ani->setFPS(20);
		}
	}
}

void camel::render(HDC hdc)
{
	_camel->aniRender(hdc, WINSIZEX / 2, WINSIZEY / 2, _ani);
}

void camel::afterRender(HDC hdc)
{
}

void camel::debugRender(HDC hdc)
{
}
