#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include "HomeWorkClass/BackGround.h"
#include "HomeWorkClass/Obstacle.h"
#include "HomeWorkClass/Player.h"

class mainGame :  public gameNode
{
private: //InGame Image
	BackGround bg;
	Obstacle obs;
	Player player;

private: //inGame var
	PlayerState pState;
	bool isCollision = false;
	bool debugShowRect = false;
	char str[25] = "press key R";

private: //inGame Logic
	bool collisionCheck();

public:
	mainGame();
	~mainGame();

	HRESULT init();	
	void release();
	void update(float DeltaTime);
	void render();
	void inputHandle();
};

