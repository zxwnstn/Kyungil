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
	Sample->init("../Common_Images/»ç³ª.bmp", WINSIZEX, WINSIZEY);

	cameraX = 100;
	cameraY = 100;

	posX = 100;
	posY = 100;
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
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		cameraX += deltaTime * cameraSpeed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		cameraX -= deltaTime * cameraSpeed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		cameraY -= deltaTime * cameraSpeed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		cameraY += deltaTime * cameraSpeed;
	}
}

void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	//camera work
	//Sample->render(memDC);
	//Sample->render(memDC, 100, 100, cameraX, cameraY, 150, 150);

	//render loop
	//Sample->loopAlphaRender(memDC, &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopX, _loopY, 200);

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
	_loopX++;
}