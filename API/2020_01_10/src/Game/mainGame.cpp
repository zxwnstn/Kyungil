#include "mainGame.h"

bool mainGame::collisionCheck()
{
	RECT playerRect = player.getPlayerRect();
	auto& v = obs.getObjs();
	for (int i = 0; i < v.size(); ++i) {
		if (UTIL::isRecRectCollision(playerRect, v[i]->getCollier())) {
			if (v[i]->getType() != "Goal") {
				pState = playerCrash;
				return true;
			}
			else{
				RECT goalRect = v[i]->getCollier();
				int temp = playerRect.bottom - goalRect.top;
				if (-1 <= temp && temp <= 1) {
					if (goalRect.left < playerRect.left && playerRect.right < goalRect.right) {
						pState = playerGoal;
						player.setPlayerState(playerGoal);
						return false;
					}				
				}			
			}
		}
	}
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

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		debugShowRect = !debugShowRect;
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
	if (!(pState & playerCrash) || !(pState & playerDie) || !playerGoal)
		inputHandle();
	if( pState == playerCrash || pState == playerGoal){
		if (KEYMANAGER->isOnceKeyDown('R')) {
			bg.release();
			player.release();
			obs.release();
			bg.init();
			player.init(getMemDC());
			obs.init(getMemDC());
		}
	}

	isCollision = collisionCheck();
	if (isCollision)
		player.setPlayerState(playerCrash);

	bg.update(deltaTime, pState);
	player.update(deltaTime);
	obs.update(deltaTime, pState);
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

	if (debugShowRect) {
		obs.debugRender();
		player.debugRender();
	}

	if (pState == playerCrash || pState == playerGoal) {
		TextOut(getMemDC(), 600, 400, str, 11);
	}
	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}