#include "stdafx.h"
#include "ExAnimationManagerScene.h"


ExAnimationManagerScene::ExAnimationManagerScene()
{
}


ExAnimationManagerScene::~ExAnimationManagerScene()
{
}

bool ExAnimationManagerScene::init()
{
	_camel = new camel;
	_camel->init();

	ufoImg = IMAGEMANAGER->addFrameImage("ufo", "../Common_Images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));
	ANIMANAGER->addDefAnimation("�����⺻", "ufo", 10);
	ufoAni = ANIMANAGER->findAnimation("�����⺻");

	EFFECTMANAGER->addEffect("��������", "ufo", 530, 32, 10, 1, 1, 0.3f, 100);

	return true;
}

void ExAnimationManagerScene::update(float _deltaTime)
{
	_camel->update(_deltaTime);
	if (KEYMANAGER->isOnceKeyDown(P1_EVENT)) {
		ufoAni = ANIMANAGER->findAnimation("�����⺻");
		ANIMANAGER->start("�����⺻");
	}
	if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE)) {
		EFFECTMANAGER->play("��������", 100, 100);
	}
}

void ExAnimationManagerScene::release()
{
	SAFE_DELETE(_camel);
}

void ExAnimationManagerScene::render(HDC hdc)
{
	//_camel->render(hdc);
	ufoImg->aniRender(hdc, m_ptMouse.x, m_ptMouse.y, ufoAni);
}

void ExAnimationManagerScene::afterRender(HDC hdc)
{
}

void ExAnimationManagerScene::debugRender(HDC hdc)
{
}
