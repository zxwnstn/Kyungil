#pragma once
#include "Collider.h"

class ColliderRect :
	public Collider
{
	FRECT collisionFiled;

public:
	ColliderRect();
	~ColliderRect();
};

