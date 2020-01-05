#pragma once
#include "Collider/Collider.h"
#include "Scene/Scene.h"

class CollisionManager
{
	std::list<class Collider*>	colliderList;			//��� collider
	std::list<class Collider*>	collisioningList;		//�浹���� Collider
	class Scene* curScene;

private:
	bool isCollision(Collider* src, Collider* dest);
	bool isInCollisioningList(Collider* src);
	void CollisionProc();

public:
	void RegisterCollider(Collider* collider);
	void SceneChange(Scene* scn);
	bool init(Scene* snc);
	void update();


private:
	DECLARE_SINGLE(CollisionManager)

};

