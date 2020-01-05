#pragma once
#include "WindowApiLib/type.h"
#include "WindowApiLib/myWinApi.h"
#include "Collider/Collider.h"
#include "Scene/Scene.h"

class Obj
{
protected:
	//Obj info
	std::shared_ptr<Scene>		includedScene;
	POSITION					objPos;

	std::shared_ptr<class Collider>	collider;		//It will defined Derived class
	ObjState					objstate;		//It will defined Derived class
	ObjType						objType;		//It will defined Derived class

	ObjType						CollidOpponent = ObjTypeNone;

public:
	//obj getter
	std::shared_ptr<Collider> getCollider() { return collider; }
	POSITION& getPos() { return objPos; }			
	ObjState getObjstate() const { return objstate; }
	ObjType getObjType() const { return objType; }

public:
	//manager interface for 
	virtual void render(HDC) = 0;
	virtual void update(float) = 0;
	virtual CollisionResult CollisionProc() = 0;

public:
	Obj(std::shared_ptr<Scene> curScene, const POSITION& pos);
	virtual ~Obj();

private:
	friend class CollisionManager;
};

