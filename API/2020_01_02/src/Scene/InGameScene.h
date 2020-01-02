#pragma once
#include "Scene/Scene.h"
#include "../Obj/Player.h"
#include "../Obj/Box.h"
#include "WindowApiLib/myWinApi.h"

class InGameScene :
	public Scene
{
	std::vector<Box> BoxList;
	Player player;

public:
	void update(float deltaTime);
	void render(HDC hdc);
	bool init();

private:
	InGameScene();
	~InGameScene();

};

