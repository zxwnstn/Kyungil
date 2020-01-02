#pragma once
#include "Scene/Scene.h"
#include "../Obj/Player.h"
#include "../Obj/Box.h"
#include "WindowApiLib/myWinApi.h"

class InGameScene :
	public Scene
{
private:
	std::list<Box> DungList;
	
	Player player;
	float timeLapse;
	float genTime = 0.3f;




private:
	void genBox();

public:
	void update(float deltaTime);
	void render(HDC hdc);

private:
	InGameScene();
	~InGameScene();

	friend Scene* CreateScene();
};