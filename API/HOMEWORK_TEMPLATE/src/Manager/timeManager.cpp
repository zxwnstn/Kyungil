#include "timeManager.h"
DEFINITION_SINGLE(timeManager)

timeManager::timeManager()
{
}

timeManager::~timeManager()
{
}

bool timeManager::init()
{
	_timer = new timer;
	_timer->init();
	return true;
}

void timeManager::release()
{
	delete _timer;
}

void timeManager::update(float lock)
{
	if (_timer != nullptr)
	{
		_timer->tick(lock);
	}
}

void timeManager::render(HDC hdc)
{
	TCHAR str[256];

	tstring strFrame;
	//배경모드
	SetBkMode(hdc, TRANSPARENT);
	//색상
	SetTextColor(hdc, RGB(0, 0, 255));
	//디버그 모드라면
	if (_timer != nullptr)
	{
		//FPS
		_tprintf_s(str, TEXT("FPS :  %d"), _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, _tcslen(str));

		//전체 경과 시간
		_stprintf_s(str, TEXT("worldTime :  %.2f"), _timer->getWorldTime());
		TextOut(hdc, 0, 20, str, _tcslen(str));
		//한프레임당 경과시간
		_stprintf_s(str, TEXT("ElapsedTime :  %.4f"), _timer->getElapsedTime());
		TextOut(hdc, 0, 40, str, _tcslen(str));
	}

	if (_timer != nullptr)
	{
		//FPS
		_stprintf_s(str, TEXT("FPS :  %d"), _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, _tcslen(str));
	}
}
