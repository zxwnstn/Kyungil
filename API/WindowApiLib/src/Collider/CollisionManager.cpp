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
			//�浹�� �ҽ�
			if (isCollision(*it, *it2)) {
				//���� collisoningList�� �̹� �־��ٸ�
				if (isInCollisioningList(*it)) {
					//collisioState = onGoing�� �ȴ�.(�浹��)
					(*it)->m_cState = CollidOnGoing;
				}
				//�ƴ϶�� ������ �浹�� �ȴ�.
				else {
					collisioningList.push_back(*it);
					(*it)->m_cState = CollidStart;
				}

			}
			//�浹�� ���ߴµ� list�� �ִٸ�
			else if(isInCollisioningList(*it)){
				//�浹�� �� ������ ���´�.
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

