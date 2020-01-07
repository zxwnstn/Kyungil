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
	//ÇÏÅ°Ã¤
	stick.p.x = m_ptMouse.x;
	stick.p.y = m_ptMouse.y;
	stick.radius = 30;
	//º¸µå
	board.left = 300.f;
	board.top = 50.f;
	board.right = 700.f;
	board.bottom = 750.f;
	//ÆÜ
	puck.c.p.x = (board.right + board.left) / 2;
	puck.c.p.y = (board.bottom + board.top) / 2;
	puck.c.radius = 20.f;
	puck.angle = PI * 1 / 6;
	puck.speed = 500.f;
	//°ñ
	opGoal.left = 450.f;
	opGoal.top = 50.f;
	opGoal.right = 550.f;
	opGoal.bottom = 100.f;

	myGoal.left = 450.f;
	myGoal.top = 700.f;
	myGoal.right = 550.f;
	myGoal.bottom = 750.f;

	//Å°ÆÛ
	keeper = { 450.f, 130.f, 550.f, 150.f };
	keeperLimitLeft = 450.f;
	keeperLimitRight = 550.f;
	keeperDx = 200.f;


	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

}

void mainGame::update(float deltaTime)
{
	mDeltaTime = deltaTime;
	gameNode::update(deltaTime);

	if (resetGame) {
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			puck.speed = 500.f;
			resetGame = false;
			puck.c.p.x = (board.right + board.left) / 2;
			puck.c.p.y = (board.bottom + board.top) / 2;
			puck.angle = rand() % 3;
		}
	}


	stickUpdate();
	keeperUpdate();
	puckUpdate();

	prevCur_x = m_ptMouse.x;
	prevCur_y = m_ptMouse.y;
}

void mainGame::render(HDC hdc)
{
	HDC memDC = getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===============================================

	//º¸µå
	Rectangle(memDC, board.left, board.top, board.right, board.bottom);
	//ÇÏÅ°Ã¤
	EllipseMakeCenter(memDC, stick.p.x, stick.p.y, stick.radius * 2, stick.radius * 2);
	//Å°ÆÛ
	Rectangle(memDC, keeper.left, keeper.top, keeper.right, keeper.bottom);
	//°ñ
	Rectangle(memDC, opGoal.left, opGoal.top, opGoal.right, opGoal.bottom);
	Rectangle(memDC, myGoal.left, myGoal.top, myGoal.right, myGoal.bottom );
	//¼¾ÅÍ¶óÀÎ
	LineMake(memDC, board.left, 400, board.right, 400);
	//ÆÜ
	EllipseMakeCenter(memDC, puck.c.p.x, puck.c.p.y, puck.c.radius * 2, puck.c.radius * 2);
	//½ºÄÚ¾î
	wsprintf(scoreText, "Score player : %d computer : %d", myPoint, opPoint);
	TextOut(memDC, 10, 10, scoreText, strlen(scoreText));

	//================================================
	getBackBuffer()->render(hdc, 0, 0);
}

void mainGame::stickUpdate()
{
	stick.p.x = m_ptMouse.x;
	stick.p.y = m_ptMouse.y;

	if (stick.p.x < board.left + stick.radius) {
		stick.p.x = board.left + stick.radius;
	}
	if (stick.p.x > board.right - stick.radius) {
		stick.p.x = board.right - stick.radius;
	}
	if (stick.p.y < (board.top + board.bottom) / 2 + stick.radius) {
		stick.p.y = (board.top + board.bottom) / 2 + stick.radius;
	}
	if (stick.p.y > board.bottom - stick.radius) {
		stick.p.y = board.bottom - stick.radius;
	}

}

void mainGame::keeperUpdate()
{
	keeper.left += keeperDx * mDeltaTime;
	keeper.right += keeperDx * mDeltaTime;

	if (keeper.right < keeperLimitLeft && keeperDx < 0)
		keeperDx = -keeperDx;
	else if(keeper.left > keeperLimitRight && keeperDx > 0)
		keeperDx = -keeperDx;

}

void mainGame::puckUpdate()
{

	//¸Å Æ½¸¶´Ù puckÀÇ ¼Ó·Â¸¸Å­, puckÀÇ °¢µµ¸¸Å­ ÀÌµ¿ÇÔ
	puck.c.p.x += puck.speed * sin(puck.angle) * mDeltaTime;
	puck.c.p.y += puck.speed * cos(puck.angle) * mDeltaTime;

	//º®¿¡ ºÎµúÄ¥½Ã
	if (!resetGame) {
		if (puck.c.p.x - puck.c.radius <= board.left) {
			puck.c.p.x = board.left + puck.c.radius;
			puck.angle = 2 * PI - puck.angle;
		}
		else if (puck.c.p.x + puck.c.radius >= board.right) {
			puck.c.p.x = board.right - puck.c.radius;
			puck.angle = 2 * PI - puck.angle;
		}

		if (puck.c.p.y - puck.c.radius <= board.top) {
			puck.c.p.y = board.top + puck.c.radius;
			puck.angle = PI - puck.angle;
		}
		else if (puck.c.p.y + puck.c.radius >= board.bottom) {
			puck.c.p.y = board.bottom - puck.c.radius;
			puck.angle = PI - puck.angle;
		}
	}
	
	//ÆÜ°ú ½ºÆ½ÀÌ ºÎµúÈú¶§
	if (UTIL::isCircleCircleCollision(puck.c, stick)) {
		puck.angle = getAngle(puck.c.p.x, puck.c.p.y, stick.p.x, stick.p.y);
		float dx = prevCur_x - m_ptMouse.x;
		float dy = prevCur_y - m_ptMouse.y;
		puck.c.p.x -= dx;
		puck.c.p.y -= dy;
		puck.speed = dx * dx + dy * dy;
		if (puck.speed > 800.f) {
			puck.speed = 800.f;
		}
		else if (puck.speed < 500.f) {
			puck.speed = 500.f;
		}
	}
	//ÆÜ°ú Å°ÆÛ°¡ ºÎµúÈú¶§
	if (UTIL::isCircleRectCollision(puck.c, keeper)) {
		puck.angle = getAngle(puck.c.p.x, puck.c.p.y, (keeper.right + keeper.left) / 2, (keeper.top + keeper.bottom) / 2);
	}

	//ÆÜ°ú °ñÀÌ ºÎµúÈú¶§ 
	if (UTIL::isCircleRectCollision(puck.c, opGoal)) {
		puck.c.p.x = -20;
		puck.c.p.y = -20;
		puck.speed = 0;
		myPoint++;
		resetGame = true;
		wsprintf(scoreText, "Score player : %d computer : %d", myPoint, opPoint);
	}
	if (UTIL::isCircleRectCollision(puck.c, myGoal)) {
		puck.c.p.x = -20;
		puck.c.p.y = -20;
		puck.speed = 0;
		opPoint++;
		resetGame = true;
		wsprintf(scoreText, "Score player : %d computer : %d", myPoint, opPoint);
	}
}
