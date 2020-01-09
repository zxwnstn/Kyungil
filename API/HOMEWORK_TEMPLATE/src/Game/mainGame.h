#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include "minimap/minimap.h"
class mainGame :  public gameNode
{
private: //InGame Image

	minimap* _minimap;

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

