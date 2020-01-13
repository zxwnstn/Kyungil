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

	handleEnemyCollision();
	handlePlayerCollision();
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================

	IMAGEMANAGER->render("사나", getMemDC());
	rocket->render();
	_enemyManager->render();
	Rectangle(getMemDC(), 10, 10, rocket->getRocketHp() * 10, 20);

	//================================================
	getBackBuffer()->render(getHDC(), 0, 0);
}

void mainGame::handleEnemyCollision()
{
	auto& bullets = rocket->getNuclear()->getVBullet();
	auto& ufos = _enemyManager->getMinion();
	
	for (auto it = bullets.begin(); it != bullets.end(); ) {
		bool isBulletCollision = false;
		for (auto it2 = ufos.begin(); it2 != ufos.end(); ) {
			if (isRectRectCollision(it->rc, (*it2)->getRect())) {
				SAFE_DELETE((*it2));
				it2 = ufos.erase(it2);
				SAFE_DELETE(it->bulletImage);
				it = bullets.erase(it);
				isBulletCollision = true;
				break;
			}
			else ++it2;
		}
		if (!isBulletCollision)
			++it;
	}
}

void mainGame::handlePlayerCollision()
{
	auto& bullets = _enemyManager->getBullet()->getBullets();
	auto& playerRect = rocket->getRect();

	for (auto it = bullets.begin(); it != bullets.end(); ) {
		if (isRectRectCollision(playerRect, it->rc)) {
			rocket->decRocketHp();
			it = bullets.erase(it);
		}
		else it++;
	}
}
