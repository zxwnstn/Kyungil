#pragma once
#include "Common/gameNode.h"

class mainGame :  public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render();//�׸��°�
};

