
#include "gameNode.h"


void gameNode::setBackBuffer()
{
	_backBuffer = new Image;
	_backBuffer->init("images/�糪.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 255, 255));
}

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	//Ÿ�̸Ӷ� ������ �ֱ⸶�� ������ �Լ��� �����Ѵ�.
	//1 : ������ �ڵ�
	//2 :  Ÿ�̸� ��ȣ
	//3 :  Ÿ�̸��ֱ� 1000=1��
	//4 :  �ֱ⸶�� ������ �Լ�
	//NULL�̸� WM_TIMER�� ����
	SetTimer(m_hWnd, 1, 10, NULL);
	//�Ŵ��� �ʱ�ȭ
	KEYMANAGER->init();

	setBackBuffer();

	return S_OK;
}

void gameNode::release()
{	//Ÿ�̸� ����

	//������ ���ϸ� ���Ḧ �ص� �޸𸮰� ������~
	KillTimer(m_hWnd, 1);
	//�Ŵ��� ����
	KEYMANAGER->releaseSingleton();
	RND->releaseSingleton();
	
	SAFE_DELETE(_backBuffer);
}

void gameNode::update(float deltaTime)
{
	//������� ���� ������� �ʴ´� true->false
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
