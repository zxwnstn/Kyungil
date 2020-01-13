#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include "minimap/minimap.h"
#include "shutting/rocket/Rocket.h"
#include "Manager/EnemyManager.h"
class mainGame :  public gameNode
{
private: //InGame Image
	Rocket* rocket;
	EnemyManager* _enemyManager;

private: //inGame var

private: //inGame Logic

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update(float DeltaTime);//�����ϴ°�
	virtual void render();//�׸��°�

	void handleEnemyCollision();
	void handlePlayerCollision();
};

