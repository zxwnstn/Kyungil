#include "BackGround.h"



BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::update(float deltaTime, PlayerState _pState)
{
	pState = _pState;
	pastTime += deltaTime;
	if (pastTime > 0.01f) {
		pastTime -= 0.01f;
		if (pState & playerRunning) {
			bgLoop += 1;
		}
	}
	
}

void BackGround::render(HDC hdc)
{
	bgImage->loopRender(hdc, &bgRect, bgLoop, 0);
}

void BackGround::init()
{
	bgImage = new Image;
	bgImage->init("images/BackGround2.bmp", WINSIZEX, WINSIZEY);
	bgRect = RectMake(0, 0, WINSIZEX, WINSIZEY);
	bgLoop = 0;
}

void BackGround::release()
{
	SAFE_DELETE(bgImage);
}
