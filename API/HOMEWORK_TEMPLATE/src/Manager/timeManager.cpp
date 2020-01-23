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
	//�����
	SetBkMode(hdc, TRANSPARENT);
	//����
	SetTextColor(hdc, RGB(0, 0, 255));
	//����� �����
	if (_timer != nullptr)
	{
		//FPS
		_tprintf_s(str, TEXT("FPS :  %d"), _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, _tcslen(str));

		//��ü ��� �ð�
		_stprintf_s(str, TEXT("worldTime :  %.2f"), _timer->getWorldTime());
		TextOut(hdc, 0, 20, str, _tcslen(str));
		//�������Ӵ� ����ð�
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
