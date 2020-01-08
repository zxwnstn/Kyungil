#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"

class mainGame :  public gameNode
{
private: //InGame Image
	Image* Sample;

	int _loopX;
	int _loopY;

	int cameraX;
	int cameraY;
	float cameraSpeed = 200.f;

	int posX;
	int posY;

private: //inGame var

private: //inGame Logic

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update(float DeltaTime);//연산하는곳
	virtual void render(HDC hdc);//그리는곳
};

