#pragma once
#include "Collider/Collider.h"
#include "Scene/Scene.h"
#include <memory>
class CollisionManager
{
	std::map<std::shared_ptr<class Obj> ,std::shared_ptr<class Collider>>	colliderList;			//모든 collider
	std::map<std::shared_ptr<Obj> ,std::shared_ptr<Collider>>	collisioningList;		//충돌중인 Collider
	class Scene*	curScene;

private:
	bool isCollision(std::shared_ptr<Collider> src, std::shared_ptr<Collider> dest);
	bool isInCollisioningList(std::shared_ptr<Obj> src);
	void CollisionProc();

public:
	void RegisterCollider(std::shared_ptr<Obj> obj, std::shared_ptr<Collider> collider);
	void SceneChange(Scene* scn);
	bool init(Scene* snc);
	void update();


private:
	DECLARE_SINGLE(CollisionManager)

};

