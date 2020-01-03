#pragma once
#include "WindowApiLib/type.h"
#include "Obj/Obj.h"

class Collider
{
private:
	CollisionState m_cState;

public:
	Collider();
	virtual ~Collider();
};

