#include "mainGame.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init();

	//image init

	_bgImage = new Image;
	_bgImage->init("images/사나.bmp", WINSIZEX, WINSIZEY);

	_rockman = new Image;
	_rockman->init("images/록맨.bmp", WINSIZEX / 2, WINSIZEY / 2, 480, 100, 10, 2, true, RGB(255, 0, 255));

	_isLeft = true;
	_isStop = false;
	_rockman->setFrameY(1);
	_index = 0;
	_countAccumulate = 0.f;

	//inGame obj init
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_rockman);
	SAFE_DELETE(_bgImage);

}  

void mainGame::update(float deltaTime)
{
	//inGame FunctionCall
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		_isLeft = true;
		_isStop = false;
		_rockman->setX(_rockman->getX() - 200.0f * deltaTime);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		_isLeft = false;
		_isStop = false;
		_rockman->setX(_rockman->getX() + 200.0f * deltaTime);
	}
	else {
		_isStop = true;
	}

	if (_isStop) {
		if (_isLeft) {
			_rockman->setFrameX(9);
		}
		else {
			_rockman->setFrameX(0);
		}
	}
	else {
		if (_isLeft) {
			_countAccumulate += deltaTime;
			_rockman->setFrameY(1);
			if (_countAccumulate >= 0.05f) {
				_countAccumulate -= 0.05f;
				_index--;
				if (_index < 0) {
					_index = 9;
				}
				_rockman->setFrameX(_index);
			}
		}
		else {
			_countAccumulate += deltaTime;
			_rockman->setFrameY(0);
			if (_countAccumulate >= 0.05f) {
				_countAccumulate -= 0.05f;
				_index++;
				if (_index >= _rockman->getMaxFrameX()) {
					_index = 0;
				}
				_rockman->setFrameX(_index);
			}
		}
	}
}

void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===============================================
	//inGame Render

	_bgImage->render(memDC);
	_rockman->frameRender(memDC, _rockman->getX(), _rockman->getY(), _rockman->getFrameX(), _rockman->getFrameY());

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}