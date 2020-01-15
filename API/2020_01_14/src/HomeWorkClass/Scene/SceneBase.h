#pragma once
#include "Common/gameNode.h"

class SceneBase : public gameNode
{
	RECT portalStore;
	RECT portalBattle1;
	RECT portalBattle2;
	RECT portalBoss;
	RECT player;

public:
	SceneBase();
	~SceneBase();

	HRESULT init(bool prev = false, const RECT& prevPos = {0,0,0,0});
	void release();
	void update(float deltaTime);
	void render();
	void debugRender();
};