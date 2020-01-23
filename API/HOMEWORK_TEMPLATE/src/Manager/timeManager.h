#pragma once
#include "timer.h"
#include "stdafx.h"

class timeManager {

public:
	bool init();
	void release();
	void update(float lock = 0.0f);
	void render(HDC hdc);

	float getElapsedTime() const	{ return _timer->getElapsedTime(); }
	float getWorldTime() const		{ return _timer->getWorldTime(); }

private:
	timer* _timer;

private:
	DECLARE_SINGLE(timeManager)
};

