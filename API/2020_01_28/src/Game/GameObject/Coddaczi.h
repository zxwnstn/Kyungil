#pragma once
#include "Object.h"

class Coddaczi :
	public Object
{
public:
	Coddaczi(int x, int y);
	~Coddaczi();

public:
	virtual bool init() override;
	virtual void update(float _deltaTime) override;

public:
	virtual void render(HDC hdc) override;
	virtual void afterRender(HDC hdc) override;
	virtual void debugRender(HDC hdc) override;

public:
	RECT& getRect() { return rect; }

private:
	RECT rect;
};

