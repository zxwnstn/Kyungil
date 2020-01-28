#pragma once
#include <Windows.h>
#include "Game/GameObject/Object.h"
#include "Common/Managers.h"
#include "Game/GameObject/PackMan.h"
#include "Game/GameObject/Coddaczi.h"

class Scene {
public:
	Scene() {};
	virtual ~Scene() {};

public:
	virtual bool init() = 0;
	virtual void update(float _deltaTime) = 0;
	virtual void release() = 0;

public:
	virtual void render(HDC hdc) = 0;
	virtual void afterRender(HDC hdc) = 0;
	virtual void debugRender(HDC hdc) = 0;
};

