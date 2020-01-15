#include "Etc/stdafx.h"
#include "minimap.h"

#define ROCKMANSPEED 5
#define CAMERASPEED 5

minimap::minimap()
{
}


minimap::~minimap()
{
}

HRESULT minimap::init()
{
	IMAGEMANAGER->addImage("배경화면", "../Common_Images/배경.bmp", WINSIZEX * 2, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("카메라", "../Common_Images/카메라.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("미니맵", "../Common_Images/배경.bmp", WINSIZEX * 2 / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	
	_rockMan = IMAGEMANAGER->addImage("록맨", "../Common_Images/록맨.bmp", 480, 120, 10, 2, true, RGB(255, 0, 255));
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
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rockMan->getX() > 0)
	{
		isLeft = true;

		if (_rockMan->getX() >= WINSIZEX / 2)
		{
			_rockMan->setX(_rockMan->getX() - ROCKMANSPEED);
		}
		else if (_camera < 0)
		{
			_camera += CAMERASPEED;
		}
		else
		{
			_rockMan->setX(_rockMan->getX() - ROCKMANSPEED);
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rockMan->getX() + 80 < WINSIZEX)
	{
		isLeft = false;

		if (_rockMan->getX() <= WINSIZEX / 2)
		{
			_rockMan->setX(_rockMan->getX() + ROCKMANSPEED);
		}
		else if (_camera > -WINSIZEX)
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			_rockMan->setX(_rockMan->getX() + ROCKMANSPEED);
		}
	}
	if (isLeft)
	{
		_count++;
		_rockMan->setFrameY(1);
		if (_count % 5 == 0)
		{
			_count = 0;
			_index--;
			if (_index < _rockMan->getMaxFrameY())
			{
				_index = 9;
			}
			_rockMan->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_rockMan->setFrameY(0);
		if (_count % 5 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= _rockMan->getMaxFrameX())
			{
				_index = 0;
			}
			_rockMan->setFrameX(_index);
		}
	}
	mini_rc = RectMakeCenter(100 + _rockMan->getX() / 10 - _camera / 10, 50 + _rockMan->getY() / 10, 10, 10);

	
}

void minimap::render()
{
	IMAGEMANAGER->render("배경화면", getMemDC(), _camera, 0);
	IMAGEMANAGER->render("미니맵", getMemDC(), 100, 50);
	//IMAGEMANAGER->frameRender("록맨", getMemDC(), _rockMan->getX(), _rockMan->getY(), _rockMan->getFrameX(), _rockMan->getFrameY());
	Rectangle(getMemDC(), mini_rc.left, mini_rc.top, mini_rc.right, mini_rc.bottom);
	IMAGEMANAGER->render("카메라", getMemDC(), 100 - _camera / 10, 50);
}
