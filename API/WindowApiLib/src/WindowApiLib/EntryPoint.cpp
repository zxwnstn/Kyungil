#include "EntryPoint.h"

HWND Application::m_hWnd = NULL;

bool Application::init(const HINSTANCE & hInst, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	m_hInstance = hInst;
	m_nCmdShow = nCmdShow;
	if (!setUpWindow())
		return false;
	return true;
}

int Application::run(){
	//messageLoop
	MSG message;
	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

bool Application::setUpWindow() {
	//register
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = m_hInstance;
	wndClass.lpfnWndProc = (WNDPROC)wndProc;
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

	return true;
}

