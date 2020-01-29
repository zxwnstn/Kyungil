#pragma once
#include "Scene.h"

class CharacterSelectScene :
	public Scene
{
public:
	CharacterSelectScene();
	~CharacterSelectScene();

public:
	bool init() override;
	void update(float _deltaTime) override;
	void release() override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

private:
	RECT bazziRect;
	RECT daoRect;
	RECT dizniRect;

	Image* bazziImg;
	Image* daoImg;
	Image* dizniImg;

	bool mouseSettedBazzi = false;
	bool mouseSettedDao = false;
	bool mouseSettedDizni = false;
};

