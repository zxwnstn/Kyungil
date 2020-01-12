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
	RECT playerRect;
	int rectAjust = 20;

	float moveDist;
	int playerX = 150;
	float playerY;
	const int groundHeight = 600;

	//animation
	int frameIdx = 0;
	float frameDelay = 0.3f;
	float framePastTime = 0.f;

	//jump
	float jumpDist = 250.f;
	float jumpPastDist = 0.0f;
	float jumpSpeed = 200.f;

public:
	void update(float deltaTime);
	void render();
	void debugRender();
	void init(HDC hdc);
	void release();

	PlayerState getPlayerState() { return pState; }
	void setPlayerState(PlayerState _pState) { pState = _pState; }
	const RECT& getPlayerRect() const { return playerRect; }
};

