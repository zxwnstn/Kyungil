#pragma once
#include "Common/SystemManagers.h"
#include "Game/GameTypes.h"

class Object
{
public:
	Object();
	virtual ~Object();

protected:
	virtual bool init() = 0;
	virtual void update(float _deltaTime) = 0;

protected:
	virtual void render(HDC hdc) = 0;
	virtual void afterRender(HDC hdc) = 0;
	virtual void debugRender(HDC hdc) = 0;
};

