#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Obj/Obj.h"
class Scene
{
protected:
	Scene();
	virtual ~Scene();
	std::vector<class Obj*> objs;

public:
	virtual void update(float) = 0;
	virtual void render(HDC) = 0;
	void eraseObj(Obj* obj);
	const std::vector<class Obj*>& GetObjs() { return objs; }


	friend class SceneManager;
};

