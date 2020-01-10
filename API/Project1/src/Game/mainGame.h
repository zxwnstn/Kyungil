#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include "minimap/minimap.h"
#include "shutting/rocket/Rocket.h"

class mainGame :  public gameNode
{
private: //InGame Image
	Rocket* rocket;
	minimap* _minimap;

private: //inGame var

private: //inGame Logic

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update(float DeltaTime);//연산하는곳
	virtual void render();//그리는곳
};

