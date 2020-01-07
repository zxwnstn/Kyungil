#include "SoundManager.h"

SoundManager* SoundManager::inst = nullptr;

SoundManager * SoundManager::GetInst()
{
	if (inst == nullptr)
		inst = new SoundManager;
	return inst;
}

bool SoundManager::init()
{
	return true;
}

void SoundManager::Destroy()
{
	if(inst != nullptr)
		delete inst;
	inst = nullptr;
}

SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::pop()
{
	sndPlaySoundA("music/bottle_pop_2.wav", SND_ASYNC | SND_NODEFAULT);
}
