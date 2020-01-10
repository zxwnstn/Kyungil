#pragma once
#include "Etc/stdafx.h"
#include "Game/gameNode.h"

class minimap : public gameNode
{
private:
	Image* _rockMan;
	int _index;
	int _count;
	int _camera;
	bool isLeft;

	RECT mini_rc;

public:
	minimap();
	~minimap();

	virtual HRESULT init();	
	virtual void release();
	virtual void update(float DeltaTime);
	virtual void render();
};

