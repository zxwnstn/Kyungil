#pragma once
#include "Image.h"

class gameNode
{
	/*
		더블버퍼링 : 
		
	*/
private:
	void setBackBuffer();
	Image* _backBuffer;

protected:
	float mDeltaTime;

public:
	gameNode();
	~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update(float deltaTime);
	virtual void render(HDC hdc);
	Image* getBackBuffer() { return _backBuffer; }
	

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

