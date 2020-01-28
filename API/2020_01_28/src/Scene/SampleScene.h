#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Common/Managers.h"

class SampleScene :
	public Scene 
{
public:
	SampleScene();
	virtual ~SampleScene();

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

