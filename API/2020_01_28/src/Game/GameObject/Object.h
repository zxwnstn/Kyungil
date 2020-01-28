#pragma once
#include <windows.h>
#include "SystemObject/Image.h"
#include "Common/Managers.h"
#include "Common/utils.h"

class Object
{
public:
	Object();
	virtual ~Object();

public:
	virtual bool init() = 0;
	virtual void update(float _deltaTime) = 0;

public:
	virtual void render(HDC hdc) = 0;
	virtual void afterRender(HDC hdc) = 0;
	virtual void debugRender(HDC hdc) = 0;
};

