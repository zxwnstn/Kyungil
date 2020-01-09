#include "mainGame.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);

	//image init
	IMAGEMANAGER->addImage("���ȭ��", "../Common_Images/���.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_minimap = new minimap();
	_minimap->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_minimap);
}  

void mainGame::update(float deltaTime)
{
	//inGame FunctionCall
	_minimap->update(deltaTime);

}

void mainGame::render(HDC hdc)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	_minimap->render(getMemDC());

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}