#pragma once
#include "Game/GameScene/Scene.h"

class ExEffectManagerScene 
	: public Scene
{
public:
	ExEffectManagerScene();
	~ExEffectManagerScene();
public:
	bool init() override;
	void release() override;
	void update(float _deltaTime) override;

public:
	void render(HDC _hdc) override;
	void afterRender(HDC _hdc) override;
	void debugRender(HDC _hdc) override;

private:
	ExEffectManagerScene * _effect;
	ExEffectManagerScene * _effect1;
	int count;
};

