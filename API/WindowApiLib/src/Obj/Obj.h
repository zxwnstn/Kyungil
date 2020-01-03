#pragma once
#include "WindowApiLib/type.h"
#include "WindowApiLib/myWinApi.h"
#include "Collider/Collider.h"
#include "Scene/Scene.h"

class Obj
{
protected:
	Collider* collider;
	Scene* includedScene;
	ObjState objstate;

public:
	virtual void render(HDC) = 0;
	virtual void update(float) = 0;
	Collider* getCollider();
	ObjState getObjstate() { return objstate; }

public:
	virtual void CollisionProc(CollisionState) = 0;

public:
	Obj(Scene* curScene);
	Obj();
	virtual ~Obj();
	bool life = true;
};

