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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update(float DeltaTime);//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�
};

