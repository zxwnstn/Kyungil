#include "ColliderRect.h"


void ColliderRect::setColliderBoundFromPos()
{
	collisionFiled.left = collidPosition.x - halfWidth;
	collisionFiled.top = collidPosition.y - halfHeight;
	collisionFiled.right = collidPosition.x + halfWidth;
	collisionFiled.bottom = collidPosition.y + halfHeight;
}

void ColliderRect::setColliderBoundFromDelta(float dx, float dy)
{
	MoveFRect(collisionFiled, dx, dy);
}

void ColliderRect::upDateCollider(float dx, float dy)
{
	collidPosition.x += dx;
	collidPosition.y += dy;
	setColliderBoundFromDelta(dx, dy);

}

ColliderRect::ColliderRect(OBJNO obj, const POSITION& _pos, float _width, float _height)
	: Collider(obj, _pos)
{
	collidBoundery = CollidBoundRect;
	width = _width;
	height = _height;
	halfHeight = height / 2;
	halfWidth = width / 2;
	setColliderBoundFromPos();
}

ColliderRect::ColliderRect(OBJNO obj, const FRECT & frec)
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
