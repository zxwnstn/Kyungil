#pragma once
#include "Common/gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include "minimap/minimap.h"
#include "shutting/rocket/Rocket.h"
#include "Manager/EnemyManager.h"

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

