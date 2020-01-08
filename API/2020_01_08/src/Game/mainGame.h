#pragma once
#include "gameNode.h"
#include "Manager/Image.h"
#include "Common/utils.h"
#include <memory>

class OpponentCar {
public:
	Image* image;
	float speed;
	float x, y;
	~OpponentCar() {
		SAFE_DELETE(image);
	}
	OpponentCar(float _x, float _y, float _speed) {
		image = new Image;
		image->init("images/opponent_car.bmp", 26, 40, true, RGB(255, 0, 255));
		x = _x;
		y = _y;
		speed = _speed;
	}
};


class mainGame :  public gameNode
{
private: //InGame Image
	Image* gameMap;
	Image* player_car;
	Image* goalLine;
	Image* startLine;
	Image* explosion;
	Image* procPointer;
	Image* ProcBar;

private: //inGame var
	list<shared_ptr<OpponentCar>> opponents;
	
	const int leftWall = 157;
	const int rightWall = 285;

	//player car
	const int playerY = 370;
	float playerX = 255.f;
	float carSpeed = 0.f;
	float carSpeedMax = 10.f;
	float carMoveSpeed = 100.f;
	
	//gen
	float coolTime;
	float genDelay = 0.4;	// 0.4초마다
	int genParam = 40;		//30프로 확률
	
	//loop
	int	loopY;
	float totalMoveDist = 0.f;

	//Line
	//start
	bool startLinePass = false;
	float startLineY = 100.f;
	//goal
	float goalDist = 500.f;
	float goalLineY = 0.f;
	bool goalIn = false;
	bool appearGoal = false;

	//colision opponenet
	bool isCollision = false;
	float collisionMaintance = 0.6f;
	float collisionTime = 0.f;
	
	//explosion
	int explosionX;
	int explosionY;
	int exFrameIdx = 0;
	float exPastTime = 0.f;
	float exFrameDelay = collisionMaintance / 8;

	//timeLimit
	float pastTime = 0.f;
	float timeLimite = 60.f;

	//
	char targetDistStr[255];
	char pastTimeStr[255];
	char timeLimiteStr[255];
	char totalMoveDistStr[255];

	//time
	int procBarHeight = 250;
	float procScale;
	int procPointerX = 435;
	int procPointerY;
	const int procPointerStartY = 390;

private: 
	//inGame Logic
	void inputHandle();
	void genOpponent();
	int judgeCollision();

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update(float DeltaTime);//연산하는곳
	virtual void render(HDC hdc);//그리는곳
};

