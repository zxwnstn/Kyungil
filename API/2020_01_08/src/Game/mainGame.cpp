#include "mainGame.h"

void mainGame::inputHandle()
{

	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		carSpeed += mDeltaTime * 1;
		if (carSpeed > carSpeedMax) {
			carSpeed = carSpeedMax;
		}
	}
	else {
		carSpeed -= mDeltaTime * 2;
		if (carSpeed < 0) {
			carSpeed = 0;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		playerX -= mDeltaTime * carMoveSpeed;
		if (playerX < leftWall) {
			playerX = leftWall;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		playerX += mDeltaTime * carMoveSpeed;
		if (playerX > rightWall)
			playerX = rightWall;
	}

}

void mainGame::genOpponent()
{
	coolTime += mDeltaTime;
	if (coolTime > genDelay) {
		coolTime -= genDelay;
		if (RND->getInt(100) > 100 - genParam) {
			opponents.push_back(make_shared< OpponentCar>(RND->getFromIntTo(leftWall, rightWall), -40, 200.f));
		}
	}
}


//플레이어 29 42
//opp 26 40
int mainGame::judgeCollision()
{
	//0 충돌 x, 1 골인, 2차량충돌
	if (appearGoal)
		if (goalLineY + 17 > playerY)
			return 1;

	for (auto it = opponents.begin(); it != opponents.end(); ++it) {
		if (isRecRectCollision(RectMake(playerX + 1, playerY, 25, 40), 
			RectMake((*it)->x + 1, (*it)->y + 1, 23, 36)))
		{
			explosionX = (*it)->x;
			explosionY = (*it)->y;
			opponents.erase(it);
			return 2;
		}
	}
	return 0;
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
	gameMap = new Image;
	gameMap->init("images/map.bmp", MAPSIZEX, MAPSIZEY);

	player_car = new Image;
	player_car->init("images/player_car.bmp", 29, 42, true, RGB(255, 0, 255));

	//inGame obj init

	startLine = new Image;
	startLine->init("images/goal.bmp", 154, 17);

	goalLine = new Image;
	goalLine->init("images/goal.bmp", 154, 17);

	explosion = new Image;
	explosion->init("images/explosion.bmp", 334, 41, 8, 1, true, RGB(255, 0, 255));

	procPointer = new Image;
	procPointer->init("images/pointer.bmp", 20, 22, true, RGB(255, 0, 255));

	ProcBar = new Image;
	ProcBar->init("images/DistBar.bmp", 5, procBarHeight + 30);
	/*for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (j) 
				opponents.push_back(make_shared< OpponentCar>( , -40, 200.f);
			else {
				opponents.push_back(make_shared< OpponentCar>(, -40, 200.f);
		}
	}*/
	
	//inGame logic var init
	loopY = 0;
	coolTime = 0.f;
	isCollision = false;

	
	procScale = goalDist / procBarHeight;
	sprintf_s(timeLimiteStr, "time limit : %.1fsec", timeLimite);
	sprintf_s(targetDistStr, "target dist : %.1fm", goalDist);
	

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(gameMap);
	SAFE_DELETE(player_car);
	SAFE_DELETE(goalLine);
	SAFE_DELETE(startLine);
	SAFE_DELETE(procPointer);
	SAFE_DELETE(ProcBar);
	SAFE_DELETE(explosion);
}

void mainGame::update(float deltaTime)
{
	mDeltaTime = deltaTime;
	pastTime += deltaTime;
	sprintf_s(pastTimeStr, "time past : %.1fsec", pastTime);

	//retire check
	if (pastTime > timeLimite) {
		MessageBox(m_hWnd, "you retired..", "junsoo CarGame", MB_OK);
		m_bLoop = false;
		return;
	}

	if (!goalIn && !isCollision) {
		inputHandle();
		//genOpponent car
		if(carSpeed > 6.f)
			genOpponent();
	}

	//collision Event
	if (isCollision) {
		collisionTime += deltaTime;
		carSpeed -= mDeltaTime * 3;
		if (carSpeed < 0) {
			carSpeed = 0;
		}
		if (collisionTime > collisionMaintance) {
			collisionTime -= collisionMaintance;
			isCollision = false;
		}
	}

	//opponent car move
	for (auto it = opponents.begin(); it != opponents.end();) {
		float relativeSpeedCoep = carSpeed - carSpeedMax / 2;
		(*it)->y += deltaTime * (*it)->speed * relativeSpeedCoep * 1 / 3;

		if ((*it)->y < -41 || (*it)->y + 40 > MAPSIZEY)
			it = opponents.erase(it);
		else ++it;
	}

	//collision
	int ret = judgeCollision(); // 1 : 골인 2 : 차량충돌
	if (ret == 1) {
		MessageBox(m_hWnd, "youWIn!", "junsoo CarGame", MB_OK);
		m_bLoop = false;
	}
	else if (ret == 2) {
		carSpeed -= 4;
		if (carSpeed < 0)
			carSpeed = 0;
		isCollision = true;
		exFrameIdx = 0;
		explosion->setFrameY(0);
	}

	//goal and start line
	if (!startLinePass) {
		if (carSpeed > 1.f) {
			startLineY += carSpeed * 1 / 3;
			if (startLineY > MAPSIZEY) {
				startLinePass = true;
				SAFE_DELETE(startLine);
			}
		}
	}
	if (!appearGoal && totalMoveDist > goalDist)
		appearGoal = true;
	if (appearGoal)
		goalLineY += carSpeed * 1 / 2;

	totalMoveDist += deltaTime * carSpeed;
	sprintf_s(totalMoveDistStr, "Dist : %.0fm", totalMoveDist);
	procPointerY = procPointerStartY - totalMoveDist / procScale;

}

void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//inGame Render
	//===============================================
	//map
	gameMap->loopRender(memDC, &RectMake(0, 0, MAPSIZEX, MAPSIZEY), 0, -(loopY += carSpeed));
	//goal and start line
	if (appearGoal) {
		goalLine->render(memDC, leftWall, goalLineY);
	}

	if (!startLinePass) {
		startLine->render(memDC, leftWall, startLineY);
	}

	//opponent
	for (auto it = opponents.begin(); it != opponents.end(); ++it) {
		(*it)->image->render(memDC, (*it)->x, (*it)->y);
	}
	player_car->render(memDC, playerX, playerY);

	if (isCollision) {
		exPastTime += mDeltaTime;
		if (exPastTime > exFrameDelay) {
			exPastTime -= exFrameDelay;
			exFrameIdx++;
			if (exFrameIdx > explosion->getMaxFrameX()) {
				exFrameIdx -= 1;
			}
			explosion->setFrameX(exFrameIdx);
		}
		explosion->frameRender(memDC, explosionX - 10, explosionY);
	}

	//UI
	TextOut(memDC, 380, 30, targetDistStr, strlen(targetDistStr));
	TextOut(memDC, 380, 50, totalMoveDistStr, strlen(totalMoveDistStr));
	TextOut(memDC, 380, 70, timeLimiteStr, strlen(timeLimiteStr));
	TextOut(memDC, 380, 90, pastTimeStr, strlen(pastTimeStr));
	
	ProcBar->render(memDC, 452, 140);
	procPointer->render(memDC, procPointerX, procPointerY);

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}