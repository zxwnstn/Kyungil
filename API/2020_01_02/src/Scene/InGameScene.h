#pragma once
#include "Scene/Scene.h"
#include "../Obj/Player.h"
#include "../Obj/Box.h"
#include "WindowApiLib/myWinApi.h"

class InGameScene :
	public Scene
{

private:
	std::vector<Obj*> objs;
	HDC memDC;
	
private:
	//gameLogic
	float timeLapse;
	float genTime = 0.1f;
	bool isJumping = false;
	bool falling = false;
	float jumpDist = 100.f;
	float jumpDy = 0.f;


private:
	void genDung();

public:
	void update(float deltaTime);
	void render(HDC hdc);

private:
	InGameScene(HDC);
	~InGameScene();

	friend Scene* CreateScene(HDC);
};