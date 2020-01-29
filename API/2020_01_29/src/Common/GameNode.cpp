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

		IMAGEMANAGER->Destroy();
		KEYMANAGER->Destroy();
		SOUNDMANAGER->Destroy();
		TIMEMANAGER->Destroy();
		SCENEMANAGER->Destroy();
		ANIMANAGER->Destroy();
	}
	ReleaseDC(m_hWnd, _hdc);
}


LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}
