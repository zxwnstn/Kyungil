#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Obj/Obj.h"
class Scene
{
protected:
	std::vector<std::shared_ptr<class Obj>> objs;
	SCENENO	sceneNo;
	OBJNO createObjSeed = 0;

public:
	virtual void update(float) = 0;
	virtual void render(HDC) = 0;
	virtual void lateUpdate(float) = 0;
	void eraseObj(std::shared_ptr<Obj> obj);
	const std::vector<std::shared_ptr<Obj>>& GetObjs() { return objs; }


public:
	Scene(SCENENO _sceneNo);
	virtual ~Scene();

	friend class SceneManager;
};

