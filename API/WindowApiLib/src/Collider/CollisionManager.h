#pragma once
#include "Collider/Collider.h"

class CollisionManager
{
	std::list<Collider> colliderList;
	std::list<Collider> collsionList;

	//basic judge collision func
	//need to templetize
	bool isCollision(Obj* src, Obj* dest);


public:
	CollisionManager();
	~CollisionManager();


	void update();

};

