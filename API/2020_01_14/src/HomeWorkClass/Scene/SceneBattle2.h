#pragma once
#include "Common/gameNode.h"

class SceneBattle2 :
	public gameNode
{
public:
	SceneBattle2();
	~SceneBattle2();
	
	HRESULT init();
	void release();
	void update(float deltaTime);
	void render();
	void debugRender() {};
};

