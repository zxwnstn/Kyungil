#include "stdafx.h"
#include "AnimationManager.h"
#include "TimeManager.h"
#include "ImageManager.h"

DEFINITION_SINGLE(AnimationManager)

AnimationManager::AnimationManager()
{
}

AnimationManager::~AnimationManager()
{
}

HRESULT AnimationManager::init()
{
	return S_OK;
}

void AnimationManager::release()
{
	deleteALL();
}

void AnimationManager::update(float _deltatime)
{
	if (_deltatime == -1.f)
		_deltatime = TIMEMANAGER->getElapsedTime();

	for (auto anime = _animation.begin(); anime != _animation.end(); ++anime)
	{
		if (!anime->second->isPlay())
			continue;
		anime->second->frameUpdate(_deltatime);
	}
}

void AnimationManager::render()
{
}

void AnimationManager::addDefAnimation(std::string animationKeyName, char * imageKeyName, int fps, bool reverse, bool loop)
{
	//이미지 및 애니메이션 초기화
	Image* img = IMAGEMANAGER->findImage(imageKeyName);
	Animation* ani = new Animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(make_pair(animationKeyName, ani));
}

void AnimationManager::addAnimation(std::string animationKeyName, char * imageKeyName, int * playArr, int arrLen, int fps, bool loop)
{
	//이미지 및 애니메이션 초기화
	Image* img = IMAGEMANAGER->findImage(imageKeyName);
	Animation* ani = new Animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(playArr, arrLen, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(make_pair(animationKeyName, ani));
}

void AnimationManager::addAnimation(std::string animationKeyName, char * imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
	//이미지 및 애니메이션 초기화
	Image* img = IMAGEMANAGER->findImage(imageKeyName);
	Animation* ani = new Animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	//이미지와 애니메이션을 초기화 후 맵에 추가한다.
	_animation.insert(std::make_pair(animationKeyName, ani));
}

void AnimationManager::start(std::string animationKeyName)
{
	auto anime = _animation.find(animationKeyName);
	anime->second->start();
}

void AnimationManager::stop(std::string animationKeyName)
{
	auto anime = _animation.find(animationKeyName);
	anime->second->stop();
}

void AnimationManager::pause(std::string animationKeyName)
{
	auto anime = _animation.find(animationKeyName);
	anime->second->pause();
}

void AnimationManager::resume(std::string animationKeyName)
{
	auto anime = _animation.find(animationKeyName);
	anime->second->resume();
}

Animation * AnimationManager::findAnimation(std::string animationKeyName)
{
	auto anime = _animation.find(animationKeyName);
	if ( anime != _animation.end())
		return anime->second;
	return nullptr;
}

void AnimationManager::deleteALL()
{
	for (auto anime = _animation.begin(); anime != _animation.end();)
	{
		if (anime->second != NULL)
		{
			SAFE_DELETE(anime->second);
			anime = _animation.erase(anime);
		}
		else
		{
			++anime;
		}
	}
}
