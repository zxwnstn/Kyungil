#pragma once
#include<Windows.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

class SoundManager
{
public:
	static SoundManager* inst;
	static SoundManager* GetInst();

	bool init();
	void Destroy();

private:
	SoundManager();
	~SoundManager();

public:
	
	void play();
	void pop();
};

