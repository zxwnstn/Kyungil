#pragma once
#include "fmod.hpp"
#include "stdafx.h"
#define CHNNEL_MAX 50

//define your sound game channel
enum class Channel {
	bgm,
	object,
	character,
	effects
};

class SoundManager
{
public:
	void init();
	void release();
	void update();

public:
	void addSound(tstring str, const tstring& fileName, bool loop = false);
	void addStream(tstring str, const tstring& fileName, bool loop = false);
	void playSound(tstring str, Channel channel);

	void pauseChannel(Channel channel);
	void resumeChannel(Channel channel);
	void stopChannel(Channel channel);
	bool isPlaying(Channel channel);
	void setVolume(Channel channel, float volume);

private:
	FMOD::System* fmodSystem;
	FMOD::Channel* ch[CHNNEL_MAX];
	FMOD_RESULT ret;
	void* extradireverdate = nullptr;

private:
	std::map<tstring, FMOD::Sound*> soundMap;

private:
	DECLARE_SINGLE(SoundManager)
};


