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
	image = IMAGEMANAGER->addImage("�糪", "../Common_Images/�糪.bmp", 0, 0, WINSIZEX, WINSIZEY);
	SOUNDMANAGER->addStream("�����", "../Common_Music/������.mp3", true);
	SOUNDMANAGER->playSound("�����", Channel::eChannelBgm);
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
