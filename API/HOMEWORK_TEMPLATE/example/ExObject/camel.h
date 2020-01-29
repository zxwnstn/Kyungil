#pragma once
#include "Game/GameObject/Object.h"

class camel :  public Object
{
private:
	Image * _camel;
	Animation* _ani;

public:
	camel();
	~camel();

public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;
};

