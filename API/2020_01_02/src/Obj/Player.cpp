#include "Player.h"



void Player::update(float deltaTime)
{
	
	MoveFRect(outerLine, eDown, deltaTime * fSpeed);
	objPos.y += deltaTime * fSpeed;

	printf("player outer line : %f %f %f %f\n", outerLine.left, outerLine.top, outerLine.right, outerLine.bottom);
	collider->upDateCollider();
}

void Player::render(HDC memDC)
{
	DrawFRect(memDC, outerLine);
}

CollisionResult Player::CollisionProc()
{
	if (collider->getCollisionState() == CollidStateStart) {
		if (CollidOpponent == ObjTypeGround) {
			adjustOuterLineFromPos();
			objPos = prevPos;
			return CollidRetMoveBack;
		}
		if (CollidOpponent == ObjTypeMissile) {
			return CollidRetAnotherEffect;
		}
	}
	return CollidRetNoChange;
}

void Player::adjustOuterLineFromPos()
{
	float dx = objPos.x - prevPos.x;
	float dy = objPos.y - prevPos.y;
	MoveFRect(outerLine, dx, dy);
}

Player::Player(Scene * scene, const FRECT & fRect, float _fSpeed = 400)
	: DynamicObj(scene, POSITION((fRect.left + fRect.right) / 2, (fRect.top + fRect.bottom) / 2))
{
	outerLine = fRect;
	fSpeed = _fSpeed;

	int temp = objType;
	temp |= (int)ObjTypePlayer;
	objType = (ObjType)temp;

	//ป๓ลย
	temp = objstate;
	temp |= (int)ObjStateActivateCollider;
	objstate = (ObjState)temp;

	collider = new class ColliderRect(this, outerLine);	//set collider same with outerLine
}

Player::~Player()
{
}

