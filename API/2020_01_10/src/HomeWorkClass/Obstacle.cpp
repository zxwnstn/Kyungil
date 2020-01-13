#include "Obstacle.h"


Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}


//장애물 젠 알고리즘을 정의 합니다.
void Obstacle::genObstacle(float deltaTime, PlayerState pState)
{
	RECT rect;
	if (moveDist > goalDist && !goalAppear) {
		goalAppear = true;
		rect = RectMake(WINSIZEX, 660, 100, 40);
		objs.push_back(new Goal(rect, img_goal));
	}

	genPastTime += deltaTime;
	if (genPastTime > genDelay) {
		genPastTime = 0;
		if (RND->getInt(100) < genRingPer) {
			rect = RectMake(WINSIZEX, 530, 10, 10);
			float RingSpeed = RND->getInt(10) + 10;
			objs.push_back(new Ring(rect, frontRing, backRing, RingSpeed));
		}
		if ((pState & playerRunning) && !goalAppear) {
			if (RND->getInt(100) < genIncePer) {
				rect = RectMake(WINSIZEX, 670, 30, 50);
				objs.push_back(new Incense(rect, img_incense));
			}
		}
	}
}



void Obstacle::update(float deltaTime, PlayerState pState)
{
	if (pState == playerCrash || pState == playerGoal) {
		return;
	}
	if (pState & playerRunning) {
		moveDist += 1;	
	}

	genObstacle(deltaTime, pState);
	for (auto it = objs.begin(); it != objs.end(); ) {
		(*it)->update(pState, deltaTime);
		if ((*it)->getCollier().left == 0) {
			delete *it;
			it = objs.erase(it);
		}
		else ++it;
	}
}

void Obstacle::firstRender()
{
	for (auto it = objs.begin(); it != objs.end(); ++it) 
		(*it)->firstRender(memDC);
}

void Obstacle::secondRender()
{
	for (auto it = objs.begin(); it != objs.end(); ++it)
		(*it)->secondRender(memDC);
}

void Obstacle::debugRender()
{
	for (auto it = objs.begin(); it != objs.end(); ++it) {
		const RECT& rect = (*it)->getCollier();
		Rectangle(memDC, rect.left, rect.top, rect.right, rect.bottom);
	}

}

void Obstacle::init(HDC hdc)
{
	memDC = hdc;

	frontRing = new Image;
	backRing = new Image;
	img_incense = new Image;
	img_goal = new Image;

	frontRing->init("images/frontRing.bmp", 24, 160, true, RGB(255, 0, 255));
	backRing->init("images/backRing.bmp", 24, 160, true, RGB(255, 0, 255));
	img_incense->init("images/incense.bmp", 48, 62, true, RGB(255, 0, 255));
	img_goal->init("images/goal.bmp", 114, 66, true, RGB(255, 0, 255));

}


void Obstacle::release()
{
	for (int i = 0; i < objs.size(); ++i) {
		SAFE_DELETE(objs[i]);
	}
	objs.clear();
	SAFE_DELETE(frontRing);
	SAFE_DELETE(backRing);
	SAFE_DELETE(img_incense);
	SAFE_DELETE(img_goal);
}
