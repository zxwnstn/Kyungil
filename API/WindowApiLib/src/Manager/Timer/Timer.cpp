#include "Timer.h"

DEFINITION_SINGLE(Timer)

Timer::Timer()
{
}


Timer::~Timer()
{
}

bool Timer::init()
{
	QueryPerformanceFrequency(&m_tSecond);
	QueryPerformanceCounter(&m_tTime);

	m_fDeltaTime = 0.f;
	m_fFPS = 0.f;
	m_fFPSTime = 0.f;
	m_iFrameMax = 60;
	m_iFrame = 0;
	return true;
}

void Timer::update()
{
	LARGE_INTEGER tTime;
	QueryPerformanceCounter(&tTime);

	m_fDeltaTime = (tTime.QuadPart - m_tTime.QuadPart) /
		(float)m_tSecond.QuadPart;

	m_tTime = tTime;
}

float Timer::GetDeltaTime() const
{
	return m_fDeltaTime;
}

float Timer::GetFPS() const
{
	return m_fFPS;
}
