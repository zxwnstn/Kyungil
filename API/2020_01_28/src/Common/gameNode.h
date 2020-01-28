#pragma once
#include "stdafx.h"
#include "Common/Managers.h"

static Image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

class gameNode {

public:
	gameNode();
	~gameNode();

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

public:
	Image* getBackBuffer()	{ return _backBuffer; }
	HDC getHDC()			{ return _hdc; }
	HDC getMemDC()			{ return _backBuffer->getMemDC(); }

public:
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

private:
	HDC	_hdc;
	static bool _managerInit;
};