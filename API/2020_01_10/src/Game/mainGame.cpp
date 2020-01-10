#include "mainGame.h"

bool mainGame::collisionCheck()
{
	return false;
}

void mainGame::inputHandle() 
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		player.setPlayerState(pState |= playerRunning);
	}
	else {
		player.setPlayerState(pState -= playerRunning);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		if(!(pState & playerJumping))
			player.setPlayerState(pState |= playerJumping);
	}
}

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
	bg.init();
	player.init(getMemDC());
	obs.init(getMemDC());

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	bg.release();
	player.release();
	obs.release();
}  



void mainGame::update(float deltaTime)
{
	//inGame FunctionCall
	pState = player.getPlayerState();
	if (!(pState & playerCrash) || !(pState & playerDie))
		inputHandle();


	bg.update(deltaTime, pState);
	player.update(deltaTime);
	obs.update(deltaTime, pState);

	isCollision = collisionCheck();
	if (isCollision)
		player.setPlayerState(playerCrash);
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	bg.render(getMemDC());
	obs.firstRender();
	player.render();
	obs.secondRender();

	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}