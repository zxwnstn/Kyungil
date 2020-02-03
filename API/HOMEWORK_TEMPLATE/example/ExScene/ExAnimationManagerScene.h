#pragma once
#include "Game/GameScene/Scene.h"
#include "../ExObject/camel.h"

class ExAnimationManagerScene 
	: public Scene
{
public:
	ExAnimationManagerScene();
	~ExAnimationManagerScene();

public:
	bool init() override;
	void update(float _deltaTime) override;
	void release() override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

private:
	camel* _camel;

	Image* ufoImg;
	Animation* ufoAni;
};

