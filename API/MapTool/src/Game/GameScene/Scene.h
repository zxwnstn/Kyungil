#pragma once
#include "stdafx.h"
#include "Common/SystemManagers.h"
#include "Game/GameObject/Object.h"
#include "Common/UTILS.h"

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

public:
	virtual LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};