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

void SoundManager::addSound(tstring str, const tstring & fileName, bool loop) {
	auto findIter = soundMap.find(str);
	if (findIter != soundMap.end())
		return;

	FMOD::Sound* sound;
	char* temp;

#ifdef _UNICODE
	temp = UTIL::ConvertWCtoC(fileName.c_str());
#else
	temp = fileName.c_str();
#endif

	if (loop) {
		ret = fmodSystem->createSound(temp, FMOD_LOOP_NORMAL, 0, &sound);
	}
	else {
		ret = fmodSystem->createSound(temp, FMOD_LOOP_OFF, 0, &sound);
	}

#ifdef _UNICODE
	delete[] temp;
#endif

	soundMap.insert(make_pair(str, sound));
}

void SoundManager::addStream(tstring str, const tstring & fileName, bool loop)
{
	auto findIter = soundMap.find(str);
	if (findIter != soundMap.end())
		return;
	FMOD::Sound* sound;
	char* temp;

#ifdef _UNICODE
	temp = UTIL::ConvertWCtoC(fileName.c_str());
#else
	temp = fileName.c_str();
#endif

	if (loop)
		ret = fmodSystem->createStream(temp, FMOD_LOOP_NORMAL, 0, &sound);
	else 
		ret = fmodSystem->createStream(temp, FMOD_LOOP_OFF, 0, &sound);

#ifdef _UNICODE
	delete[] temp;
#endif

	soundMap.insert(make_pair(str, sound));
}

void SoundManager::playSound(tstring str, Channel channel)
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
