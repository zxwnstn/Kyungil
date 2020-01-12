#pragma once
#include "Etc/stdafx.h"
#include "Obj.h"

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
	Image* img_incense;
	Image* img_goal;

	std::vector<Obj*> objs;

	void genObstacle(float deltaTime, PlayerState pState);
	float genPastTime = 0.f;
	float genDelay = 1.5f; 
	//float genDelay = 2.5f;
	int moveDist = 0;
	int goalDist = 200;

	int genRingPer = 35;
	int genIncePer = 20;
	//int genRingPer = 10;
	//int genIncePer = 10;
	bool goalAppear = false;

public:
	const std::vector<Obj*>& getObjs() const { return objs; }
	void update(float deltaTime, PlayerState pState);
	void init(HDC hdc);
	void firstRender();
	void secondRender();
	void debugRender();
	void release();
};

