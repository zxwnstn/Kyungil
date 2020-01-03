#include "ApplicationCore.h"
bool ApplicationCore::m_bLoop = true;

bool ApplicationCore::init(const HINSTANCE & hInst, int nCmdShow) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	m_hInstance = hInst;
	m_nCmdShow = nCmdShow;
	if (!setUpWindow())
		return false;

	if (!GET_SINGLE(InputManager)->init())
		return false;
	if (!GET_SINGLE(SceneManager)->init(m_hWnd, m_hDc))
		return false;
	if (!GET_SINGLE(Timer)->init())
		return false;

	srand(time(NULL));
	return true;
}

int ApplicationCore::run() {
	MSG message;
	while (m_bLoop) {
		if (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		Logic();
	}

	return message.wParam;
}

void ApplicationCore::update()
{
	GET_SINGLE(Timer)->update();
	m_fDeltaTime = GET_SINGLE(Timer)->GetDeltaTime();
}

void ApplicationCore::render()
{
}

LRESULT ApplicationCore::dWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_TIMER:
		break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

bool ApplicationCore::setUpWindow() {
	//register
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = m_hInstance;
	wndClass.lpfnWndProc = (WNDPROC)dWndProc;
	//else wndClass.lpfnWndProc = (WNDPROC)wndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndClass);

	//CreateWindow
	m_hWnd = CreateWindow(WINNAME, WINNAME, WS_OVERLAPPEDWINDOW,
		WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY,
		NULL, (HMENU)NULL, m_hInstance, NULL
	);

	//adjust Window
	RECT rc{ 0, 0, WINSIZEX , WINSIZEY };
	AdjustWindowRect(&rc, WINSTYLE, false);
	SetWindowPos(m_hWnd, NULL, WINSTARTX, WINSTARTY, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
	ShowWindow(m_hWnd, m_nCmdShow);

	m_hDc = GetDC(m_hWnd);

	return true;
}

ApplicationCore::~ApplicationCore()
{
	RELEASE_SINGLE(InputManager);
	RELEASE_SINGLE(SceneManager);
	RELEASE_SINGLE(Timer);

	ReleaseDC(m_hWnd, m_hDc);
}