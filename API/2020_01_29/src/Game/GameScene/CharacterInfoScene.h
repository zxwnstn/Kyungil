#pragma once
#include "Scene.h"
#include "Game/GameObject/Character.h"

class CharacterInfoScene :
	public Scene
{
public:
	CharacterInfoScene();
	~CharacterInfoScene();

public:
	bool init() override;
	void update(float _deltaTime) override;
	void release() override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;
};

