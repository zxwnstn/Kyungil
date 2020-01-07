#pragma once
#include"gameNode.h"
#include "Image.h"
#include "utils.h"

struct Puck {
	Circle c;
	float angle;
	float speed;
};

class mainGame :  public gameNode
{

private:
	UTIL::FRECT board;
	FRECT opGoal;
	FRECT myGoal;
	FRECT keeper;
	float keeperLimitLeft;
	float keeperLimitRight;
	float keeperDx;

	float prevCur_x;
	float prevCur_y;

	int myPoint = 0;
	int opPoint = 0;

	char scoreText[255];

	Circle stick;
	Puck puck;
	
	bool resetGame = false;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update(float DeltaTime);//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

private:
	void stickUpdate();
	void keeperUpdate();
	void puckUpdate();

};

