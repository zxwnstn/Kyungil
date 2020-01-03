#pragma once
#include "WindowApiLib/type.h"
#include "Obj/Obj.h"

class Collider
{
private:
	CollisionState m_cState;
	Obj* includedObj;

public:
	Collider() {}
	Collider(Obj* obj);
	virtual ~Collider();
	

	friend class CollisionManager;
};

