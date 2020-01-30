#pragma once
#include "../../vendor/fmod/inc/fmod.hpp"
#define CHNNEL_MAX 50

//define your sound game channel
enum class Channel {
	eChannelBgm,
	eChannelEffect
};

class SoundManager
{
public:
	void init();
	void release();
	void update();

public:
	void addSound(std::string str, const std::string& fileName, bool loop = false);
	void addStream(std::string str, const std::string& fileName, bool loop = false);
	void playSound(std::string str, Channel channel);

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
	std::map<std::string, FMOD::Sound*> soundMap;

private:
	DECLARE_SINGLE(SoundManager)
};

#define SOUNDMANAGER SoundManager::GetInst()