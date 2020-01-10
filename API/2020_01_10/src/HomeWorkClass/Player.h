#pragma once
#include "Etc/stdafx.h"

class Player
{
public:
	Player();
	~Player();

private:
	HDC memDC;
	PlayerState pState;

	Image* cur;
	Image* run;
	Image* jump;
	Image* runAndJump;
	Image* dead;

	float moveDist;
	RECT playerRect;
	int playerX = 150;
	int playerY;
	const int groundHeight = 500;
	//animation
	int frameIdx = 0;
	float frameDelay = 0.3f;
	float framePastTime = 0.f;

	//jump
	float jumpDelay = 1.f;
	float jumpPastTime = 0.0f;
	float jumpSpeed = 200.f;

public:
	void update(float deltaTime);
	void render();
	void init(HDC hdc);
	void release();

	PlayerState getPlayerState() { return pState; }
	void setPlayerState(PlayerState _pState) { pState = _pState; }
};

