#pragma once
#include "../../WindowApiLib/myWinApi.h"

class Timer
{
	LARGE_INTEGER	m_tSecond;
	LARGE_INTEGER	m_tTime;
	float			m_fDeltaTime;
	float			m_fFPS;
	float			m_fFPSTime;
	int				m_iFrameMax;
	int				m_iFrame;

public:
	bool init();
	void update();
	float GetDeltaTime() const;
	float GetFPS() const;

private:
	DECLARE_SINGLE(Timer)
};

