#pragma once
#include "Manager/Image.h"

static Image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);


class gameNode
{
private:

	//void setBackBuffer();
	HDC		_hdc;
	bool	_managerInit;


protected:
	float mDeltaTime;

public:
	gameNode();
	~gameNode();

	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update(float deltaTime);
	virtual void render(HDC hdc);
	Image* getBackBuffer() { return _backBuffer; }
	
	HDC getHDC() { return _hdc; }
	HDC getMemDC() { return _backBuffer->getMemDC(); }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};