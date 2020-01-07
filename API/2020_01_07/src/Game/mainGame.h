#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#define GROUNDHEIGHT 630

class mainGame :  public gameNode
{
private: //InGame Image
	Image* rockMan;
	Image* backGround;
	float rockManSpeed = 200.f;

private: //inGame var
	bool isLeft = true;
	bool isJump = false;
	bool isMove = false;
	bool onGround = false;
	int frameIndex = 0;
	float jumpDist = 100.f;
	float jumpAccumulate = 0.f;
	float frameChangeTime = 0.05f;
	float frameAccumulate = 0.f;


	//obstacle
	RECT obs;

private: //inGame Logic
	bool isCharacterOnGround();
	void affectGravity(float deltaTime);

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update(float DeltaTime);//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�
};

