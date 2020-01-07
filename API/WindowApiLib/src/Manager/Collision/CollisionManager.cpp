#include "CollisionManager.h"
#include "Manager.h"

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

bool CollisionManager::isInCollisioningList(std::shared_ptr<Obj> obj)
{
	if (collisioningList.end() != collisioningList.find(obj)) {
		return true;
	}
	return false;
}



void CollisionManager::RegisterCollider(std::shared_ptr<Obj> obj ,std::shared_ptr<Collider> collider)
{
	colliderList.insert(make_pair(obj, collider));
}

void CollisionManager::SceneChange(Scene* scn)
{

	//TODO : think about SceneChange..
	colliderList.clear();
	collisioningList.clear();

	curScene = GET_SINGLE(SceneManager)->getCurScene();
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
			if (isCollision((*src).second, (*dest).second)) {

				//src�� ����
				//���� collisoningList�� �̹� �־��ٸ�
				if (isInCollisioningList((*src).first)) {
					//collisioState = onGoing�� �ȴ�.(�浹��)
					(*src).second->m_cState = CollidStateOnGoing;
				}
				//�ƴ϶�� ������ �浹�� �ȴ�.
				else {
					(*src).second->m_cState = CollidStateStart;
					(*src).first->CollidOpponent = (*dest).first->objType;
					collisioningList.insert(*src);
				}

				//dest�� ����
				if (isInCollisioningList((*dest).first)) {
					(*dest).second->m_cState = CollidStateOnGoing;
				}
				else {
					(*dest).second->m_cState = CollidStateStart;
					(*dest).first->CollidOpponent = (*src).first->objType;
					collisioningList.insert(*dest);
				}
			}
			//�浹�� ���ߴµ� list�� �ִٸ�
			else if(isInCollisioningList((*src).first)){
				(*src).second->m_cState = CollidStateRelease;
				(*src).first->CollidOpponent = ObjTypeNone;
				collisioningList.insert(*src);
			}
			else if (isInCollisioningList((*dest).first)) {
				(*dest).second->m_cState = CollidStateRelease;
				(*dest).first->CollidOpponent = ObjTypeNone;
				collisioningList.insert(*dest);
			}
		}
	}
	CollisionProc();
}

bool CollisionManager::init(Scene* snc)
{
	curScene = snc;

	auto objs = snc->GetObjs();
	for (int i = 0; i < objs.size(); ++i) {
		if ((int)objs[i]->objstate & (int)ObjStateActivateCollider) {
			colliderList.insert(std::make_pair(objs[i], objs[i]->collider));
		}
	}

	return true;
}

void CollisionManager::CollisionProc()
{
	for (auto it = collisioningList.begin(); it != collisioningList.end();) {
		CollisionResult ret = (*it).first->CollisionProc();
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
			(*it).second->getCollisionState() = CollidSateNone;
			(*it).first->CollidOpponent = ObjTypeNone;
			it = collisioningList.erase(it);
			break;
		case CollidRetdeleted:
			colliderList.erase(colliderList.find((*it).first));
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

