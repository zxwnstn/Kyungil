#include "stdafx.h"
#include "SoundManager.h"
DEFINITION_SINGLE(SoundManager)

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::init() {
	ret = FMOD::System_Create(&fmodSystem);
	ret = fmodSystem->init(32, FMOD_INIT_NORMAL, extradireverdate);
}

void SoundManager::addSound(std::string str, const std::string & fileName, bool loop) {
	auto findIter = soundMap.find(str);
	if (findIter != soundMap.end())
		return;

	FMOD::Sound* sound;

	if (loop) {
		ret = fmodSystem->createSound(fileName.c_str() , FMOD_LOOP_NORMAL, 0, &sound);
	}
	else {
		ret = fmodSystem->createSound(fileName.c_str(), FMOD_LOOP_OFF, 0, &sound);
	}

	soundMap.insert(make_pair(str, sound));
}

void SoundManager::addStream(std::string str, const std::string & fileName, bool loop)
{
	auto findIter = soundMap.find(str);
	if (findIter != soundMap.end())
		return;
	FMOD::Sound* sound;

	if (loop)
		ret = fmodSystem->createStream(fileName.c_str(), FMOD_LOOP_NORMAL, 0, &sound);
	else 
		ret = fmodSystem->createStream(fileName.c_str(), FMOD_LOOP_OFF, 0, &sound);

	soundMap.insert(make_pair(str, sound));
}

void SoundManager::playSound(std::string str, Channel channel)
{
	auto findIter = soundMap.find(str);
	if (findIter == soundMap.end()) {
		return;
	}
	fmodSystem->playSound(findIter->second, 0, false, &ch[(int)channel]);
}

void SoundManager::release() {
	fmodSystem->release();
	fmodSystem->close();
}

void SoundManager::pauseChannel(Channel channel) {
	ch[(int)channel]->setPaused(true);
}

void SoundManager::resumeChannel(Channel channel) {
	ch[(int)channel]->setPaused(false);
}

void SoundManager::stopChannel(Channel channel)
{
	ch[(int)channel]->stop();
}

bool SoundManager::isPlaying(Channel channel)
{
	bool ret;
	ch[(int)channel]->isPlaying(&ret);
	return ret;
}

void SoundManager::setVolume(Channel channel, float volume)
{
	ch[(int)channel]->setVolume(volume);
}

void SoundManager::update()
{
	fmodSystem->update();
}
