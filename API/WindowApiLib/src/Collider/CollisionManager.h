#pragma once
#include "Collider/Collider.h"
#include "Scene/Scene.h"
class CollisionManager
{
	std::list<Collider*> colliderList;
	std::list<Collider*> collisioningList;
	Scene* curScene;

private:
	bool isCollision(Collider* src, Collider* dest);
	bool isInCollisioningList(Collider* src);
	void RegisterCollider();
	void ColliderProc();

public:
	void SceneChange(Scene* scn);
	void update();


private:
	DECLARE_SINGLE(CollisionManager)

};

