#pragma once
#include "Collider/Collider.h"
#include "Scene/Scene.h"
#include <memory>
class CollisionManager
{
	std::list<std::shared_ptr<class Collider>>	colliderList;			//모든 collider
	std::list<std::shared_ptr<Collider>>	collisioningList;		//충돌중인 Collider
	std::shared_ptr<class Scene> curScene;

private:
	bool isCollision(std::shared_ptr<Collider> src, std::shared_ptr<Collider> dest);
	bool isInCollisioningList(std::shared_ptr<Collider> src);
	void CollisionProc();

public:
	void RegisterCollider(std::shared_ptr<Collider> collider);
	void SceneChange(std::shared_ptr<class Scene> scn);
	bool init(std::shared_ptr<Scene> snc);
	void update();


private:
	DECLARE_SINGLE(CollisionManager)

};

