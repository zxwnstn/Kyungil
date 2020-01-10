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

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}  

void mainGame::update(float deltaTime)
{
	//inGame FunctionCall
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================


	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}