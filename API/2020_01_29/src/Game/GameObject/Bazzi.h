#pragma once
#include "Character.h"

class Bazzi
	: public Character
{
public:
	Bazzi();
	~Bazzi();
public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void afterRender(HDC hdc) override;
};

