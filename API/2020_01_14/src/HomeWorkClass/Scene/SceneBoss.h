#pragma once
#include "Common/gameNode.h"

class SceneBoss :
	public gameNode
{
public:
	SceneBoss();
	~SceneBoss();

	HRESULT init();
	void release();
	void update(float deltaTime);
	void render();
	void debugRender() {};

};

