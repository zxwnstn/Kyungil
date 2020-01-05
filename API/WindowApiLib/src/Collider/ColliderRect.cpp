#include "ColliderRect.h"


void ColliderRect::setColliderBoundFromPos()
{
	collisionFiled.left = collidPosition.x - halfWidth;
	collisionFiled.top = collidPosition.y - halfHeight;
	collisionFiled.right = collidPosition.x + halfWidth;
	collisionFiled.bottom = collidPosition.y + halfHeight;

	printf("player colliderFiled : %f %f %f %f\n", collisionFiled.left, collisionFiled.top, collisionFiled.right, collisionFiled.bottom);
}

void ColliderRect::upDateCollider()
{
	collidPosition = includedObj->getPos();
	setColliderBoundFromPos();
	//printf("%f %f\n", collidPosition.x, collidPosition.y);
	//printf("%f %f\n", includedObj->getPos().x, includedObj->getPos().y);
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
	:Collider(obj, POSITION((frec.left + frec.right) / 2, (frec.bottom + frec.top) / 2))
{
	collidBoundery = CollidBoundRect;
	width = frec.right - frec.left;
	height = frec.bottom - frec.top;
	halfHeight = height / 2;
	halfWidth = width / 2;
	collisionFiled = frec;
}


ColliderRect::~ColliderRect()
{
}
