#include "stdafx.h"
#include "ExEffectManagerScene.h"
#include "Common/SystemManagers.h"

ExEffectManagerScene::ExEffectManagerScene()
{
}


ExEffectManagerScene::~ExEffectManagerScene()
{
}

bool ExEffectManagerScene::init()
{
	IMAGEMANAGER->addImage("���", "../Common_Images/�糪.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	EFFECTMANAGER->addEffect("����", "../Common_Images/explosion.bmp", 832, 62, 32, 62, 1, 0.5f, 100);
	EFFECTMANAGER->addEffect("����1", "../Common_Images/explosion1.bmp", 4355, 135, 335, 135, 1, 1.f, 100);
	EFFECTMANAGER->addEffect("����", "../Common_Images/ufo.bmp", 530, 32, 53, 32, 1, 0.3f, 100);
	count = 0;
	return true;
}

void ExEffectManagerScene::release()
{

}

void ExEffectManagerScene::update(float _deltaTime)
{

	if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		EFFECTMANAGER->play("����1", m_ptMouse.x, m_ptMouse.y);
	}
	if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE))
	{
		EFFECTMANAGER->play("����", m_ptMouse.x, m_ptMouse.y);
	}
	/*count++;

	if (count % 10 == 0)
	{
		EFFECTMANAGER->play("����", UTIL::getFromIntTo(100, 300), UTIL::getFromIntTo(100, 300));
	}*/

}

void ExEffectManagerScene::render(HDC _hdc)
{
	IMAGEMANAGER->render("���", _hdc);
}

void ExEffectManagerScene::afterRender(HDC _hdc)
{
}

void ExEffectManagerScene::debugRender(HDC _hdc)
{
}
