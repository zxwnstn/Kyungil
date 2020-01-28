#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Game/GameObject/Object.h"
#include "Common/Managers.h"
#include "Game/GameObject/PackMan.h"
#include "Game/GameObject/Coddaczi.h"

class PackManScene
	:public Scene
{
public:
	PackManScene();
	~PackManScene();

public:
	bool init();
	void update(float _deltaTime);
	void release();

public:
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

private:
	std::shared_ptr<PackMan> packMan;
	std::vector<std::shared_ptr<Coddaczi>> coddaczis;
	RECT back = { 0, 0, WINSIZEX, WINSIZEY };
	Image* backGround;
};

