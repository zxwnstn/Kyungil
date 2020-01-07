#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"

class mainGame :  public gameNode
{
private: //InGame Image
	Image* Sample;

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

