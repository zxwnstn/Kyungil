#pragma once
#include "WindowApiLib/type.h"
#include "WindowApiLib/myWinApi.h"
#include "Collider/Collider.h"
#include "Scene/Scene.h"

class Obj
{
protected:
	//Obj info
	class Scene*		includedScene;
	POSITION			objPos;

	class Collider*		collider;		//It will defined Derived class
	ObjState			objstate;		//It will defined Derived class
	ObjType				objType;		//It will defined Derived class

	
	ObjType				CollidOpponent = ObjTypeNone;

public:
	//obj getter
	POSITION getPos() { return objPos; }			
	Collider* getCollider() { return collider; }
	ObjState getObjstate() const { return objstate; }
	ObjType getObjType() const { return objType; }

public:
	//manager interface for 
	virtual void render(HDC) = 0;
	virtual void update(float) = 0;
	virtual CollisionResult CollisionProc() = 0;

public:
	Obj(Scene * curScene, const POSITION& pos);
	virtual ~Obj();

private:
	friend class CollisionManager;
};

