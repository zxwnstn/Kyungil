#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::update(float deltaTime)
{
	//달리면서 점프
	if ((pState & playerRunning) && (pState & playerJumping)) {
		cur = runAndJump;
		jumpPastTime += deltaTime;

		if (jumpPastTime < jumpDelay / 2) playerY -= deltaTime * jumpSpeed;
		else playerY += deltaTime * jumpSpeed;

		if (jumpPastTime > jumpDelay + 0.2f) {
			jumpPastTime = 0.f;
			pState ^= playerJumping;
			playerY = groundHeight;
			cur = run;
		}
		playerRect.top = playerY;
		playerRect.bottom = playerY + run->getHeight();
		return;
	}
	//달리기
	if (pState & playerRunning) {
		framePastTime += deltaTime;
		if (framePastTime > frameDelay) {
			framePastTime = 0;
			frameIdx++;
		}
		cur = run;
		return;
	}
	//점프만
	if (pState & playerJumping) {
		cur = jump;
		jumpPastTime += deltaTime;

		if (jumpPastTime < jumpDelay / 2) playerY -= deltaTime * jumpSpeed;
		else playerY += deltaTime * jumpSpeed;

		if (jumpPastTime > jumpDelay + 0.2f) {
			jumpPastTime = 0.f;
			pState ^= playerJumping;
			playerY = groundHeight;
			cur = run;
		}		
		playerRect.top = playerY;
		playerRect.bottom = playerY + run->getHeight();
		return;
	}
	//충돌
	if (pState & playerCrash) {

		return;
	}
}

void Player::render()
{
	//Rectangle(memDC, playerRect.left, playerRect.top, playerRect.right, playerRect.bottom);
	if (pState & playerRunning) {
		if (frameIdx > cur->getMaxFrameX())
			frameIdx = 0;
		cur->frameRender(memDC, playerX, playerY, frameIdx, 0);
		return;
	}
	if (pState & playerJumping) {
		cur->render(memDC, playerX, playerY);
		return;
	}
	if (pState & playerStop) {
		cur = run;
		cur->frameRender(memDC, playerX, playerY, 1, 0);
		return;
	}
	if (pState & playerCrash) {
		cur = dead;
		cur->render(memDC, playerX, playerY);
		return;
	}
	
}

void Player::init(HDC hdc)
{
	memDC = hdc;
	pState = playerStop;

	run = new Image;
	jump = new Image;
	runAndJump = new Image;
	dead = new Image;

	//run->init("images/run.bmp", 63, 40, 2, 1, true, COLOR_MAGENTA);
	run->init("images/run.bmp", 189, 120, 2, 1, true, COLOR_MAGENTA);
	//jump->init("images/jump.bmp", 32, 40, true, COLOR_MAGENTA);
	jump->init("images/jump.bmp", 96, 120, true, COLOR_MAGENTA);
	//runAndJump->init("images/runAndJump.bmp", 105, 40, 3, 1, true, COLOR_MAGENTA);
	runAndJump->init("images/runAndJump.bmp", 315, 120, 3, 1, true, COLOR_MAGENTA);
	//dead->init("images/dead.bmp", 32, 40, true, COLOR_MAGENTA);
	dead->init("images/dead.bmp", 96, 120, true, COLOR_MAGENTA);

	playerY = groundHeight;
	playerRect.left = playerX + 10;
	playerRect.top = playerY;
	playerRect.right = playerX + run->getHeight() - 30;
	playerRect.bottom = groundHeight + run->getHeight();
}

void Player::release()
{
	SAFE_DELETE(run);
	SAFE_DELETE(jump);
	SAFE_DELETE(dead);
	SAFE_DELETE(runAndJump);
}
