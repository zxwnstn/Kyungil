#include "stdafx.h"
#include "SampleScene.h"

SampleScene::SampleScene()
{
}


SampleScene::~SampleScene()
{
}

bool SampleScene::init()
{
	image = IMAGEMANAGER->addImage("사나", "../Common_Images/사나.bmp", 0, 0, WINSIZEX, WINSIZEY);
	SOUNDMANAGER->addStream("배경음", "../Common_Music/나만봄.mp3", true);
	SOUNDMANAGER->playSound("배경음", Channel::eChannelBgm);
	return true;
}

void SampleScene::update(float _deltaTime)
{
	SOUNDMANAGER->update();
}

void SampleScene::render(HDC hdc)
{
	image->render(hdc);
}

void SampleScene::afterRender(HDC hdc)
{
}

void SampleScene::debugRender(HDC hdc)
{
}

void SampleScene::release()
{
}
