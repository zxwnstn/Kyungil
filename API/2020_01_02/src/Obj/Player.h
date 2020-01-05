#pragma once

#include "Obj/DynamicObj.h"
#include "Collider/ColliderRect.h"

class Player : public DynamicObj
{
private:
	void adjustOuterLineFromPos();

public:
	FRECT outerLine;
	float fSpeed;

public:
	Player(std::shared_ptr<Scene> scene, const FRECT& fRect, float _fSpeed);
	virtual ~Player();

	virtual void update(float deltaTime) override;
	virtual void render(HDC memDC) override;
	virtual CollisionResult CollisionProc() override;
};

