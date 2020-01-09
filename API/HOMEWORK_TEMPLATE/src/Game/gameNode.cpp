#include "gameNode.h"

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	_hdc = GetDC(m_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_managerInit = managerInit;
	//SetTimer(m_hWnd, 1, 10, NULL);
	//매니저 초기화
	
	if (_managerInit) {
		KEYMANAGER->init();
		IMAGEMANAGER->init();
	}
	return E_NOTIMPL;
}

void gameNode::release()
{

	//KillTimer(m_hWnd, 1);
	//매니저 해제
	if (_managerInit) {
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		RND->releaseSingleton();
	}
	ReleaseDC(m_hWnd, _hdc);
}

void gameNode::update(float deltaTime)
{
	//더블버퍼 이후 사용하지 않는다 true->false
	InvalidateRect(m_hWnd, NULL, false);
}
void gameNode::render(HDC hdc)
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
	case WM_TIMER:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			m_bLoop = false;
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}
