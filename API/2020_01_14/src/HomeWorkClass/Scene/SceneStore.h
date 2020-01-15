#pragma once
#include "Common/gameNode.h"

class SceneStore :
	public gameNode
{
public:
	SceneStore();
	~SceneStore();

	HRESULT init();
	void release();
	void update(float deltaTime);
	void render();
	void debugRender() {};
};

