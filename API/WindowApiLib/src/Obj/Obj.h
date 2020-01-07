#pragma once
#include "WindowApiLib/type.h"
#include "WindowApiLib/myWinApi.h"
#include "Collider/Collider.h"
#include "Scene/Scene.h"

class Obj
{
protected:
	//Obj info
	SCENENO						includedScene;
	OBJNO						objNo;
	POSITION					objPos;

	std::shared_ptr<class Collider>	collider;
	ObjState					objstate;		//It will defined Derived class
	ObjType						objType = ObjTypeNone;		//It will defined Derived class
	ObjType						CollidOpponent = ObjTypeNone;

public:
	//obj getter
	std::shared_ptr<Collider> getCollider() { return collider; }
	POSITION& getPos() { return objPos; }			
	ObjState getObjstate() const { return objstate; }
	ObjType getObjType() const { return objType; }

public:
	//manager interface for 
	virtual CollisionResult CollisionProc() = 0;
	virtual void render(HDC) = 0;
	virtual void update(float) = 0;
	virtual void lateUpdate(float) = 0;

public:
	Obj(SCENENO _includedScene, const POSITION& pos, OBJNO _objNo);
	virtual ~Obj();

private:
	friend class CollisionManager;
};

