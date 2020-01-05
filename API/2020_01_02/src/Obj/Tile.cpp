#include "Tile.h"

void Tile::update(float deltaTime)
{
	//Tile is no move..
}

void Tile::render(HDC memDC)
{
	DrawFRect(memDC, outerLine);
}

CollisionResult Tile::CollisionProc()
{
	return CollidRetNoChange;
}

Tile::Tile(std::shared_ptr<Scene> scene, const FRECT& fRect)
	:StaticObj(scene, POSITION((fRect.left + fRect.right)/2, (fRect.top + fRect.bottom)/2))
{
	//타입
	int temp = objType;
	temp |= (int)ObjTypeGround;
	objType = (ObjType)temp;

	//상태
	temp = objstate;
	temp |= (int)ObjStateActivateCollider;
	objstate = (ObjState)temp;

	outerLine = fRect;
	collider = std::make_shared<ColliderRect>(this, outerLine);	//set collider same with outerLine
	GET_SINGLE(CollisionManager)->RegisterCollider(collider);
}

Tile::~Tile()
{
}
