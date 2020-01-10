#pragma once
#include "Etc/stdafx.h"

class BackGround
{
public:
	BackGround();
	~BackGround();

private:
	PlayerState pState;

	Image* bgImage;
	RECT bgRect;
	int bgWidth;
	int bgHeight;
	int bgLoop;

	float pastTime = 0.f;

public:
	void init();
	void update(float deltaTime, PlayerState _pState);
	void render(HDC hdc);
	void release();
};

