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
	image = IMAGEMANAGER->findImage("�糪");
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
