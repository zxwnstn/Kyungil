#include "stdafx.h"
#include "timer.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//timeGetTime �Լ��� ����ϱ� ���� ���̺귯�� �߰�
//�����찡 ���۵ǰ� �� ���� �ð��� ������.

Timer::Timer()
{
}


Timer::~Timer()
{
}

HRESULT Timer::init()
{
	//QueryPerformanceCounter ���ػ� Ÿ�̸��� ���� cpu�� Ŭ������ ��� �༮
	//QueryPerformanceFrequency ���ػ� Ÿ���̸��� ���ļ��� ��ȯ��.
	//���� Ÿ�̸� �������θ� üũ����.
	//���� Ÿ�̸Ӹ� �����ϸ� �ʴ� ����ũ�μ�������� ���� ��.
	//(1/1000000)
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		//�ʴ� �ð� ��� ����
		_timeScale = 1.0f / _periodFrequency;

	}
	else
	{
		_isHardware = false;
		//�и������� ������ �ð����� �ʴ� 1000�� ī��Ʈ
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPStimeElapsed = 0.0f;
	_worldTime = 0.0f;

	return S_OK;
}

void Timer::tick(float lockFPS)
{
	//���� Ÿ�̸Ӹ� �����Ѵٸ�
	if (_isHardware)
	{
		//������ ����ũ���� ������ �����.(1/1000000)
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{//�������� ������ time�Լ��� �̿�.(1/1000)
		_curTime = timeGetTime();
	}
	//������ �ð��� ����ð��� �����
	_timeElapsed = (_curTime - _lastTime) * _timeScale;


	if (lockFPS > 0.0f)
	{
		//���� �������� �ð��� �����Ҷ����� ������
		while (_timeElapsed < (1.0f / lockFPS) )
		{
			if (_isHardware)QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			_timeElapsed = (_curTime - _lastTime)* _timeScale;
		}
	}

	_lastTime = _curTime;				//������ �ð��� ���
	_FPSFrameCount++;					//�ڵ����� ������ ī��Ʈ ����
	_FPStimeElapsed += _timeElapsed;	//�ʴ� ������ �ð� ����� ����
	_worldTime += _timeElapsed;			//��ü �ð� ����� ����

	if (_FPStimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPStimeElapsed = 0.0f;
	}
}

unsigned long Timer::getFrameRate(char * str) const
{
	if (str != NULL){
		sprintf(str, "FPS : %d", _frameRate);
	}
	return _frameRate;
}
