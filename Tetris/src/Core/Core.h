#pragma once
#include "../etc/Game.h"

class Core{
public:
	static Core* m_pInst;
	static Core* GetInst();
	void Destroy();
	bool init();

private:	
	Core();
	~Core();

private:
	bool m_bLoop = true;
	double dropTime[10];
	int turnCnt;

public:
	int run();
};

