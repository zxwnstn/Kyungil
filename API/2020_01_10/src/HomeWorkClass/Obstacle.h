#pragma once
#include "Etc/stdafx.h"

class Obstacle
{
public:
	Obstacle();
	~Obstacle();

private:
	HDC memDC;
	PlayerState pState;
	Image* frontRing;
	Image* backRing;
	Image* incense;
	vector<RECT> RingsRect;
	vector<RECT> incensesRect;

public:
	void update(float deltaTime, PlayerState pState);
	void firstRender();
	void secondRender();
	void init(HDC hdc);
	void render();
	void release();
};

