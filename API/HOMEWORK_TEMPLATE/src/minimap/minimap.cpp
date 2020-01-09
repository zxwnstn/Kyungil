#include "minimap.h"



minimap::minimap()
{
}


minimap::~minimap()
{
}

HRESULT minimap::init()
{
	IMAGEMANAGER->addImage("배경화면", "../Common_Images/배경.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("카메라", "../Common_Images/카메라.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("미니맵", "../Common_Images/배경.bmp", WINSIZEX * 2 / 10, WINSIZEY * 2 / 10, true, RGB(255, 0, 255));
	
	_rockMan = IMAGEMANAGER->addImage("미니맵", "../Common_Images/록맨.bmp", 480, 120, 10, 2, true, RGB(255, 0, 255));
	mini_rc = RectMakeCenter(100 + _rockMan->getX() / 10 - _camera / 10, 50 + _rockMan->getY() / 10, 10, 10);
	_rockMan->setX(WINSIZEX / 2);
	_rockMan->setY(WINSIZEY / 2);

	_index = 0;
	_count = 0;
	_camera = 0;
	isLeft = false;
	return S_OK;
}

void minimap::release()
{
}

void minimap::update(float DeltaTime)
{
	
}

void minimap::render(HDC hdc)
{
	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	IMAGEMANAGER->render("미니맵", getMemDC(), 100, 50);
	IMAGEMANAGER->frameRender("록맨", getMemDC(), _rockMan->getX(), _rockMan->getY(), _rockMan->getFrameX(), _rockMan->getFrameY());
	Rectangle(getMemDC(), mini_rc.left, mini_rc.top, mini_rc.right, mini_rc.bottom);
	IMAGEMANAGER->render("카메라", getMemDC(), 100 - _camera / 10, 50);
}
