#include "mainGame.h"

bool mainGame::isCharacterOnGround()
{
	if (rockMan->getY() + rockMan->getFrameheight() > GROUNDHEIGHT) {
		return true;
	}
	return false;
}

void mainGame::affectGravity(float deltaTime)
{
	rockMan->setY(rockMan->getY() + deltaTime * rockManSpeed);
	if (isCharacterOnGround()) {
		rockMan->setY(GROUNDHEIGHT - rockMan->getFrameheight());
		onGround = true;
	}
	else {
		onGround = false;
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
	gameNode::init();

	//image init
	rockMan = new Image;
	rockMan->init("../Common_Images/록맨.bmp", WINSIZEX / 2, WINSIZEY/2, 480, 100, 10, 2, true, RGB(255, 0, 255));

	backGround = new Image;
	!backGround->init("images/록맨배경.bmp", WINSIZEX, WINSIZEY, false);

	//inGame obj init
	obs = RectMake(260, 410, 95, 250);

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(rockMan);
}  

void mainGame::update(float deltaTime)
{
	if (!isJump) {
		affectGravity(deltaTime);
	}
	//inGame FunctionCall
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		rockMan->setFrameY(1);
		isMove = true;
		isLeft = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		rockMan->setFrameY(0);
		isMove = true;
		isLeft = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE)) {
		if (!isJump && onGround) {
			isJump = true;
			isMove = true;
		}
	}

	frameAccumulate += deltaTime;
	
	if (isJump) {
		jumpAccumulate += deltaTime * rockManSpeed;
		if (jumpAccumulate > jumpDist) {
			jumpAccumulate = 0.f;
			isJump = false;
		}
		else {
			rockMan->setY(rockMan->getY() - deltaTime * rockManSpeed);
		}
	}

	if (isMove) {
		if (isLeft) {
			rockMan->setX(rockMan->getX() - deltaTime * rockManSpeed);
			if (frameAccumulate > frameChangeTime) {
				frameAccumulate -= frameChangeTime;
				frameIndex--;
				if (frameIndex < 0) {
					frameIndex = rockMan->getMaxFrameX();
				}
				rockMan->setFrameX(frameIndex);
			}

			if (isRectRectCollision(rockMan->getBoundingBox(), obs)) {
				rockMan->setX(rockMan->getX() + deltaTime * rockManSpeed);
			}

		}
		else {
			rockMan->setX(rockMan->getX() + deltaTime * rockManSpeed);
			if (frameAccumulate > frameChangeTime) {
				frameAccumulate -= frameChangeTime;
				frameIndex++;
				if (frameIndex > rockMan->getMaxFrameX()) {
					frameIndex = 0;
				}
				rockMan->setFrameX(frameIndex);
			}
		}
	}

	if (frameAccumulate > frameChangeTime) {
		frameAccumulate -= frameChangeTime;
	}
	isMove = false;
}




void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===============================================
	//inGame Render

	backGround->render(memDC);
	rockMan->frameRender(memDC, rockMan->getX(), rockMan->getY());
	//DrawRect(memDC, obs);
	//DrawRect(memDC, rockMan->getBoundingBox());

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}