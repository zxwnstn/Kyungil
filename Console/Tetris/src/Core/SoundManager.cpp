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

void SoundManager::play()
{
	sndPlaySoundA("C:\\Users\\KGA_17\\source\\repos\\Project1\\Project3\\a.wav", SND_ASYNC | SND_LOOP | SND_NOSTOP);
}

void SoundManager::pop()
{
	sndPlaySoundA("bottle_pop_2.wav", SND_ASYNC | SND_NODEFAULT);
}
