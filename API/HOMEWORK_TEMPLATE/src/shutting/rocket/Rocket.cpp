#include "Rocket.h"

Rocket::Rocket() 
{
}

Rocket::~Rocket()
{
	release();
}

HRESULT Rocket::init()
{
	_player = IMAGEMANAGER->addImage("rocket", "../Common_Images/rocket.bmp", 
		WINSIZEX / 2, WINSIZEY / 2, 52, 64, true, RGB(255, 0, 255));


	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getWidth(), _player->getHeight());

	_missile = new missile;
	_missile->init(100, 500);

	_nuclear = new Nuclear;
	_nuclear->init(100, 1000);

	return S_OK;
}

void Rocket::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _player->getX() > 0) {
		rc.left -= PLAYERSPEED;
		rc.right -= PLAYERSPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _player->getX() + _player->getWidth() < WINSIZEX){
		rc.left += PLAYERSPEED;
		rc.right += PLAYERSPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _player->getY() > 0){
		rc.top -= PLAYERSPEED;
		rc.bottom -= PLAYERSPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player->getY() + _player->getHeight() < WINSIZEY){
		rc.top += PLAYERSPEED;
		rc.bottom += PLAYERSPEED;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		_nuclear->fire(rc.right - (rc.right - rc.left) / 2, rc.top - 50);
	}
	_nuclear->update();
} 

void Rocket::render()
{
	//_player->render(getMemDC(), _player->getX(), _player->getY());
	_player->render(getMemDC(), rc.left, rc.top);
	//Rectangle(getMemDC() ,rc.left, rc.top, rc.right, rc.bottom);
	_nuclear->render();
}

void Rocket::release()
{
	SAFE_DELETE(_missile);
}
