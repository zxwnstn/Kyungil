#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Obj/Obj.h"
class Scene
{
protected:
	Scene();
	virtual ~Scene();
	std::vector<Obj*> objs;

public:
	std::vector<Obj*>* getObjs();
	virtual void update(float) = 0;
	virtual void render(HDC) = 0;

	friend class SceneManager;
};

