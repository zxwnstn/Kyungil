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
	
	IMAGEMANAGER->addImage("사나", "../Common_Images/사나.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("bullet", "../Common_Images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "../Common_Images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));
	rocket = new Rocket;
	rocket->init();

	_enemyManager = new EnemyManager;
	_enemyManager->init();
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
	_enemyManager->update();
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	IMAGEMANAGER->render("사나", getMemDC());
	rocket->render();
	_enemyManager->render();

	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}