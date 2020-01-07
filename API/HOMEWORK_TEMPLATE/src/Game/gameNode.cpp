
#include "gameNode.h"


void gameNode::setBackBuffer()
{
	_backBuffer = new Image;
	_backBuffer->init("images/사나.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 255, 255));
}

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	//타이머란 일정한 주기마다 정해진 함수를 실행한다.
	//1 : 윈도우 핸들
	//2 :  타이머 번호
	//3 :  타이머주기 1000=1초
	//4 :  주기마다 실행할 함수
	//NULL이면 WM_TIMER가 실행
	SetTimer(m_hWnd, 1, 10, NULL);
	//매니저 초기화
	KEYMANAGER->init();

	setBackBuffer();

	return S_OK;
}

void gameNode::release()
{	//타이머 해제

	//해제를 안하면 종료를 해도 메모리가 줄줄줄~
	KillTimer(m_hWnd, 1);
	//매니저 해제
	KEYMANAGER->releaseSingleton();
	RND->releaseSingleton();
	
	SAFE_DELETE(_backBuffer);
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
