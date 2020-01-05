#include "ColliderRect.h"


void ColliderRect::setColliderBoundFromPos()
{
	collisionFiled.left = collidPosition.x - halfWidth;
	collisionFiled.top = collidPosition.x - halfHeight;
	collisionFiled.right = collidPosition.x + halfWidth;
	collisionFiled.bottom = collidPosition.x + halfHeight;
}

void ColliderRect::upDateCollider()
{
	collidPosition = includedObj->getPos();
	setColliderBoundFromPos();
}

ColliderRect::ColliderRect(Obj* obj, const POSITION& _pos, float _width, float _height)
	: Collider(obj, _pos)
{
	collidBoundery = CollidBoundRect;
	width = _width;
	height = _height;
	halfHeight = height / 2;
	halfWidth = width / 2;
	setColliderBoundFromPos();
}

ColliderRect::ColliderRect(Obj * obj, const FRECT & frec)
	:Collider(obj, POSITION((frec.left + frec.right)/2, (frec.bottom + frec.top)/2))
{
	collidBoundery = CollidBoundRect;
	width = (frec.left + frec.right) / 2;
	height = (frec.bottom + frec.top) / 2;
	halfHeight = height / 2;
	halfWidth = width / 2;
	collisionFiled = frec;
}


ColliderRect::~ColliderRect()
{
}
