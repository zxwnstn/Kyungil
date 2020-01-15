#include "Etc/stdafx.h"
#include "SceneBase.h"



SceneBase::SceneBase()
{
}


SceneBase::~SceneBase()
{
}



HRESULT SceneBase::init(bool prev, const RECT & prevPos)
{
	portalStore = {0, 500, 100 ,600};
	portalBattle1 = { WINSIZEX - 100, 500, WINSIZEX ,600 };
	portalBattle2 = { 500, 0, 600 ,100 };
	portalBoss = { 500, WINSIZEY - 100, 600 ,WINSIZEY };

	return E_NOTIMPL;
}

void SceneBase::release()
{
}

void SceneBase::update(float deltaTime)
{
}

void SceneBase::render()
{
}

void SceneBase::debugRender()
{
}
