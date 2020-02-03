#include "stdafx.h"
#include "gameNode.h"
bool GameNode::_managerInit = false;

GameNode::GameNode()
{
}

GameNode::~GameNode()
{
}

void GameNode::update()
{
	InvalidateRect(m_hWnd, NULL, false);
}
void GameNode::render()
{
}

HRESULT GameNode::init()
{
	_hdc = GetDC(m_hWnd);
	_managerInit = false;

	if (!_managerInit) {
		_managerInit = true;
		srand(time(NULL));
		IMAGEMANAGER->init();
		KEYMANAGER->init();
		SOUNDMANAGER->init();
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		ANIMANAGER->init();
		EFFECTMANAGER->init();
	}
	return S_OK;
}


void GameNode::release()
{
	//매니저 해제
	if (_managerInit) {
		IMAGEMANAGER->release();
		KEYMANAGER->release();
		SOUNDMANAGER->release();
		TIMEMANAGER->release();
		SCENEMANAGER->release();
		ANIMANAGER->release();
		EFFECTMANAGER->release();

		IMAGEMANAGER->Destroy();
		KEYMANAGER->Destroy();
		SOUNDMANAGER->Destroy();
		TIMEMANAGER->Destroy();
		SCENEMANAGER->Destroy();
		ANIMANAGER->Destroy();
		EFFECTMANAGER->Destroy();
	}
	ReleaseDC(m_hWnd, _hdc);
}