#include "Obj.h"



Collider * Obj::getCollider()
{
	return collider;
}

Obj::Obj()
{
}


Obj::Obj(Scene * curScene)
{
	collider = new Collider(this);
	objstate = ObjActivate;
	includedScene = curScene;
}

Obj::~Obj()
{
	SAFE_DELETE(collider);
}
