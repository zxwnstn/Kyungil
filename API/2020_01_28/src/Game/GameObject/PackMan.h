#pragma once
#include "Object.h"

enum class PackManDir {
	eUp,
	eDown,
	eLeft,
	eRight
};

class PackMan :
	public Object
{
public:
	PackMan();
	~PackMan();

public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

public:
	UTIL::IRECT& getRect() { return collisionRect; }

private:
	int posX, posY;
	UTIL::IRECT collisionRect;
	int speed = 2;

private:
	Image* image;
	int imageIdxX = 0;
	int imageIdxY = 0;
	float changeDelay = 0.1f;
	float changePastTime = 0.f;
	PackManDir state = PackManDir::eDown;
};

