#pragma once
#include "Common/gameNode.h"

class SceneBattle1 :
	public gameNode
{
public:
	SceneBattle1();
	~SceneBattle1();

	HRESULT init();
	void release();
	void update(float deltaTime);
	void render();
	void debugRender() {};
};

