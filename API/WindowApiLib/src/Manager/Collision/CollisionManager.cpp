#include "CollisionManager.h"

DEFINITION_SINGLE(CollisionManager)

bool CollisionManager::isCollision(std::shared_ptr<Collider> src, std::shared_ptr<Collider> dest)
{
	//rect rect collision
	if (src->collidBoundery == CollidBoundRect && dest->collidBoundery == CollidBoundRect) {
		//src l t r b
		float srcLeft = src->collidPosition.x - src->halfWidth;
		float srcTop = src->collidPosition.y - src->halfHeight;
		float srcRight = src->collidPosition.x + src->halfWidth;
		float srcBottom = src->collidPosition.y + src->halfHeight;
		//dest l t r b	   
		float destLeft = dest->collidPosition.x - dest->halfWidth;
		float destTop = dest->collidPosition.y - dest->halfHeight;
		float destRight = dest->collidPosition.x + dest->halfWidth;
		float destBottom = dest->collidPosition.y + dest->halfHeight;

		//rect Collision fomula
		if (srcLeft <= destRight && srcRight >= destLeft 
			&& srcTop <= destBottom && srcBottom >= destTop)
		{
			//printf("src %d %d", src->)
			return true;
		}
	}
	//rect circle collision
	else if(src->collidBoundery == CollidBoundRect && dest->collidBoundery == CollidBoundCircle){
		//TODO : implementation
	}
	//circle rect collision
	else if(src->collidBoundery == CollidBoundCircle && dest->collidBoundery == CollidBoundRect){
		//TODO : implementation
	}
	//circle circle collision
	else if(src->collidBoundery == CollidBoundCircle && dest->collidBoundery == CollidBoundCircle){
		//TODO : implementation
	}

	return false;
}

bool CollisionManager::isInCollisioningList(std::shared_ptr<Collider> src)
{
	auto it = collisioningList.begin();
	auto itEnd = collisioningList.end();
	for (it; it != itEnd; ++it) {
		if (*it == src)
			return true;
	}
	return false;
}



void CollisionManager::RegisterCollider(std::shared_ptr<Collider> collider)
{
	if(collider->includedObj->includedScene == curScene)
		colliderList.push_back(collider);
}

void CollisionManager::SceneChange(std::shared_ptr<Scene> scn)
{
	curScene = scn;

	//TODO : think about SceneChange..
	//colliderList.clear();
	//collisioningList.clear();
}

void CollisionManager::update()
{
	//Collision Check N^2 ver
	auto src = colliderList.begin();
	auto srcEnd = colliderList.end();
	auto dest = colliderList.begin();
	auto destEnd = colliderList.end();
	if (colliderList.size()) {
		srcEnd--;
		dest++;
	}
	for (src; src != srcEnd; ++src) {
		for (dest; dest != destEnd; ++dest) {
			//�浹�� �ҽ�
			if (isCollision(*src, *dest)) {

				//src�� ����
				//���� collisoningList�� �̹� �־��ٸ�
				if (isInCollisioningList(*src)) {
					//collisioState = onGoing�� �ȴ�.(�浹��)
					(*src)->m_cState = CollidStateOnGoing;
				}
				//�ƴ϶�� ������ �浹�� �ȴ�.
				else {
					(*src)->m_cState = CollidStateStart;
					(*src)->includedObj->CollidOpponent = (*dest)->includedObj->objType;
					collisioningList.push_back(*src);
				}

				//dest�� ����
				if (isInCollisioningList(*dest)) {
					(*dest)->m_cState = CollidStateOnGoing;
				}
				else {
					(*dest)->m_cState = CollidStateStart;
					(*dest)->includedObj->CollidOpponent = (*src)->includedObj->objType;
					collisioningList.push_back(*dest);
				}
			}
			//�浹�� ���ߴµ� list�� �ִٸ�
			else if(isInCollisioningList(*src)){
				(*src)->m_cState = CollidStateRelease;
				(*src)->includedObj->CollidOpponent = ObjTypeNone;
				collisioningList.push_back(*src);
			}
			else if (isInCollisioningList(*dest)) {
				(*dest)->m_cState = CollidStateRelease;
				(*dest)->includedObj->CollidOpponent = ObjTypeNone;
				collisioningList.push_back(*dest);
			}
		}
	}
	CollisionProc();
}

bool CollisionManager::init(std::shared_ptr<Scene> snc)
{
	curScene = snc;

	auto objs = snc->GetObjs();
	for (int i = 0; i < objs.size(); ++i) {
		if ((int)objs[i]->objstate & (int)ObjStateActivateCollider) {
			colliderList.push_back(objs[i]->collider);
		}
	}

	return true;
}

void CollisionManager::CollisionProc()
{
	for (auto it = collisioningList.begin(); it != collisioningList.end();) {
		CollisionResult ret = (*it)->includedObj->CollisionProc();
		switch (ret)
		{
		case CollidRetNoChange:
			++it;
			break;
		case CollidRetAnotherEffect:
			//TODO : implementation
			++it;
			break;
		case CollidRetMoveBack:
			(*it)->getCollisionState() = CollidSateNone;
			(*it)->includedObj->CollidOpponent = ObjTypeNone;
			it = collisioningList.erase(it);
			break;
		case CollidRetdeleted:
			for (auto it2 = colliderList.begin(); it2 != colliderList.end(); ++it2) {
				if (*it == *it2) {
					colliderList.erase(it2);
					break;
				}
			}
			it = collisioningList.erase(it);					
			break;
		}
	}
}


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

