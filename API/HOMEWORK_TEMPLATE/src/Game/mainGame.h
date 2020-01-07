#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"

class mainGame :  public gameNode
{
private:
	Image* _bgImage;
	Image* _rockman;

	int _index;
	float _countAccumulate;
	bool _isLeft;
	bool _isStop;

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

