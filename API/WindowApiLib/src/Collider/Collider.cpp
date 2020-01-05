#include "Collider.h"

Collider::Collider(Obj * obj, const POSITION & _collidPosition)
	:collidPosition(_collidPosition), includedObj(obj)
{
	if((int)includedObj->getObjstate() & (int)ObjStateActivateCollider)
		GET_SINGLE(CollisionManager)->RegisterCollider(this);
}

Collider::~Collider()
{
}
