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
	IMAGEMANAGER->addImage("¹è°æ", "../Common_Images/»ç³ª.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	////Æø¹ß ÀÌÆåÆ® ÀÌ¹ÌÁö
	//IMAGEMANAGER->addImage("Æø¹ß", "images/explosion.bmp", 832, 62, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Æø¹ß1", "images/explosion1.bmp", 4355, 135, true, RGB(255, 0, 255));


	//_effect = new effect;
	//_effect->init(IMAGEMANAGER->findImage("Æø¹ß"), 32, 62, 1, 0.5f);


	//_effect1 = new effect;
	//_effect1->init(IMAGEMANAGER->findImage("Æø¹ß1"), 335, 135, 1, 0.4f);

	EFFECTMANAGER->addEffect("Æø¹ß", "../Common_Images/explosion.bmp", 832, 62, 32, 62, 1, 0.5f, 100);
	EFFECTMANAGER->addEffect("Æø¹ß1", "../Common_Images/explosion1.bmp", 4355, 135, 335, 135, 1, 0.3f, 100);
	
	count = 0;
	return true;
}

void ExEffectManagerScene::release()
{
	/*SAFE_DELETE(_effect);
	SAFE_DELETE(_effect1);*/
}

void ExEffectManagerScene::update(float _deltaTime)
{
	if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE))
	{
		//_effect->startEffect(m_ptMouse.x, m_ptMouse.y);
		EFFECTMANAGER->play("Æø¹ß", m_ptMouse.x, m_ptMouse.y);
	}
	if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		//_effect1->startEffect(m_ptMouse.x, m_ptMouse.y);
		EFFECTMANAGER->play("Æø¹ß1", m_ptMouse.x, m_ptMouse.y);
	}

	//_effect->update();
	//_effect1->update();

	count++;

	if (count % 10 == 0)
	{
		EFFECTMANAGER->play("Æø¹ß", UTIL::getFromIntTo(100, 300), UTIL::getFromIntTo(100, 300));
	}

}

void ExEffectManagerScene::render(HDC _hdc)
{
	IMAGEMANAGER->render("¹è°æ", _hdc);
	//_effect->render(_hdc);
	//_effect1->render();
}

void ExEffectManagerScene::afterRender(HDC _hdc)
{
}

void ExEffectManagerScene::debugRender(HDC _hdc)
{
}
