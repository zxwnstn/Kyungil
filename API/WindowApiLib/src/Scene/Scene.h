#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Obj/Obj.h"
class Scene
{
protected:
	std::vector<std::shared_ptr<class Obj>> objs;

public:
	virtual void update(float) = 0;
	virtual void render(HDC) = 0;
	void eraseObj(std::shared_ptr<Obj> obj);
	const std::vector<std::shared_ptr<Obj>>& GetObjs() { return objs; }

public:
	Scene();
	virtual ~Scene();

	friend class SceneManager;
};

