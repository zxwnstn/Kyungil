#include "core/Application.h"


int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {

	if (!Application::GetInst()->init(hInst, nCmdShow)) {
		Application::GetInst()->Destroy();
		return -1;
	}

	int iRev = Application::GetInst()->run();
	Application::GetInst()->Destroy();
	return iRev;
}