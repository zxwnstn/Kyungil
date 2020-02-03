#pragma once
#include "Scene.h"

class SampleScene2 :
	public Scene
{
public:
	SampleScene2();
	virtual ~SampleScene2();

public:
	bool init() override;
	void release() override;

public:
	void update(float _deltaTime) override;
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

private:
	Image* image;
};