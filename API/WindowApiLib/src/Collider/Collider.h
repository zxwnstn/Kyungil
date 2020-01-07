#pragma once
#include "WindowApiLib/type.h"
#include "Obj/Obj.h"
#include "Manager/Collision/CollisionManager.h"

class Collider
{
protected:
	CollisionState		m_cState = CollidSateNone;
	CollidBoundary		collidBoundery;
	OBJNO				includedObj;

protected:
	POSITION			collidPosition;
	float width;
	float height;
	float halfWidth;
	float halfHeight;

public:
	virtual void upDateCollider(float dx, float dy) = 0;
	CollisionState& getCollisionState() { return m_cState; }

public:
	Collider(OBJNO obj, const POSITION& _collidPosition);
	virtual ~Collider();

	friend class CollisionManager;
};

