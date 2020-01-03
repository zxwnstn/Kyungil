#include "CollisionManager.h"

DEFINITION_SINGLE(CollisionManager)

bool CollisionManager::isCollision(Collider* src, Collider* dest)
{
	
	return true;
}

bool CollisionManager::isInCollisioningList(Collider * src)
{
	auto it = collisioningList.begin();
	auto itEnd = collisioningList.end();
	for (it; it != itEnd; ++it) {
		if (*it == src)
			return true;
	}
	return false;
}



void CollisionManager::RegisterCollider()
{
	auto objs = curScene->getObjs();
	for (auto it = objs->begin(); it != objs->end();) {
		if ((*it)->getObjstate() & (int)ObjActivateCollider) {
			colliderList.push_back((*it)->getCollider());
		}
	}
}

void CollisionManager::SceneChange(Scene * scn)
{
	curScene = scn;
}

void CollisionManager::update()
{
	RegisterCollider();

	for (auto it = colliderList.begin(); it != colliderList.end(); ) {
		for (auto it2 = ++colliderList.begin(); it != colliderList.end();) {
			//충돌을 할시
			if (isCollision(*it, *it2)) {
				//만약 collisoningList에 이미 있었다면
				if (isInCollisioningList(*it)) {
					//collisioState = onGoing이 된다.(충돌중)
					(*it)->m_cState = CollidOnGoing;
				}
				//아니라면 최초의 충돌이 된다.
				else {
					collisioningList.push_back(*it);
					(*it)->m_cState = CollidStart;
				}

			}
			//충돌을 안했는데 list에 있다면
			else if(isInCollisioningList(*it)){
				//충돌이 막 해제된 상태다.
				(*it)->m_cState = CollidRelease;
				collisioningList.push_back(*it);
			}
		}
	}
	ColliderProc();
	auto it = collisioningList.begin();
	auto itEnd = collisioningList.end();
	for (it; it != itEnd; ++it) {
		if ((*it) == nullptr)
			it = colliderList.erase(it);
		else it++;
	}

	colliderList.clear();
}

void CollisionManager::ColliderProc()
{
	for (auto it = collisioningList.begin(); it != collisioningList.end(); ++it) {
		(*it)->includedObj->CollisionProc();
	}
}


CollisionManager::CollisionManager()
{
}




CollisionManager::~CollisionManager()
{
}

