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
	Sample = new Image;
	Sample->init("../Common_Images/sigong.bmp", 40, 40, true);

	//inGame obj init


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(Sample);
}  

void mainGame::update(float deltaTime)
{
	//inGame FunctionCall

}

void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===============================================
	//inGame Render

	Sample->render(memDC, WINSIZEX / 2 - 20, WINSIZEY / 2 - 20);

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}