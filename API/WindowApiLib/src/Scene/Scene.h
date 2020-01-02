#pragma once
#include "../WindowApiLib/myWinApi.h"

class Scene
{
protected:
	Scene();
	virtual ~Scene();

public:
	virtual void update(float) = 0;
	virtual void render(HDC) = 0;

	friend class SceneManager;
};

