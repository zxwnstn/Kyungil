#pragma once
#include "SystemObject/timer.h"

class TimeManager {

public:
	bool init();
	void release();
	void update(float lock = 0.0f);
	void render(HDC hdc);

	float getElapsedTime() const	{ return _timer->getElapsedTime(); }
	float getWorldTime() const		{ return _timer->getWorldTime(); }

private:
	Timer* _timer;

private:
	DECLARE_SINGLE(TimeManager)
};

#define TIMEMANAGER TimeManager::GetInst()