#pragma once
#include "SystemObject/Animation.h"

class AnimationManager
{
public:
	HRESULT init();
	void release();
	void update(float _deltatime = -1.f);
	void render();
	void deleteALL();

public:
	//ó������ ������
	void addDefAnimation(std::string animationKeyName, char* imageKeyName, int fps, bool reverse = false, bool loop = false);
	//�迭�� ��Ƽ�
	void addAnimation(std::string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	//����
	void addAnimation(std::string animationKeyName, char* imageKeyName, int start, int end, int fps,bool reverse =  false, bool loop = false);
	Animation* findAnimation(std::string animationKeyName);

public:
	void start(std::string animationKeyName);
	void stop(std::string animationKeyName);
	void pause(std::string animationKeyName);
	void resume(std::string animationKeyName);

private:
	typedef std::map<std::string, Animation*> arrAnimation;
	arrAnimation _animation;

private:
	DECLARE_SINGLE(AnimationManager)
};

#define ANIMANAGER AnimationManager::GetInst()