#include "mainGame.h"
#include "Scene/Scene.h"

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
	
	SCENEMANAGER->addScene("사나love", new Scene);
	SCENEMANAGER->changeScene("사나love");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}  

void mainGame::update()
{
	TIMEMANAGER->update();
	SCENEMANAGER->update(TIMEMANAGER->getElapsedTime());
	//inGame FunctionCall
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	SCENEMANAGER->render();

	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}