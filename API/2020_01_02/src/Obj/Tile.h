#pragma once
#include "Obj/StaticObj.h"
#include "Collider/ColliderRect.h"

class Tile : public StaticObj
{
private:
	FRECT outerLine;

public:
	Tile(std::shared_ptr<Scene> scene, const FRECT& fRect);
	virtual ~Tile();

	virtual void update(float deltaTime) override;
	virtual void render(HDC memDC) override;
	virtual CollisionResult CollisionProc() override;
};

