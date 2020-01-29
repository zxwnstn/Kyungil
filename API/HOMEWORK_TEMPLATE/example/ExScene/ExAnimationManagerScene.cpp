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
	return true;
}

void ExAnimationManagerScene::update(float _deltaTime)
{
	_camel->update(_deltaTime);
}

void ExAnimationManagerScene::release()
{
	SAFE_DELETE(_camel);
}

void ExAnimationManagerScene::render(HDC hdc)
{
	_camel->render(hdc);
}

void ExAnimationManagerScene::afterRender(HDC hdc)
{
}

void ExAnimationManagerScene::debugRender(HDC hdc)
{
}
