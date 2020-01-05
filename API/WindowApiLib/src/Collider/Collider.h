#pragma once
#include "WindowApiLib/type.h"
#include "Obj/Obj.h"
#include "Manager/Collision/CollisionManager.h"

class Collider
{
protected:
	CollisionState		m_cState = CollidSateNone;
	CollidBoundary		collidBoundery;
	std::shared_ptr<class Obj>	includedObj;

protected:
	POSITION			collidPosition;
	float width;
	float height;
	float halfWidth;
	float halfHeight;

public:
	virtual void upDateCollider() = 0;
	CollisionState& getCollisionState() { return m_cState; }

public:
	Collider(std::shared_ptr<Obj> obj, const POSITION& _collidPosition);
	virtual ~Collider();

	friend class CollisionManager;
};

