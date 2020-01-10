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
	rocket = new Rocket;
	rocket->init();

	_minimap = new minimap;
	_minimap->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(rocket);
}  

void mainGame::update(float deltaTime)
{
	//inGame FunctionCall
	rocket->update();
	_minimap->update(deltaTime);
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	_minimap->render();
	rocket->render();


	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}