#pragma once
#include "state.h"
#include <string>

class HeroState {
public:
	HeroState();
	virtual ~HeroState();
public:
	virtual void inputHandle(class player& p, int input) = 0;
	virtual void update(class player& p) = 0;
	virtual void render() = 0;

protected:
	std::string direction[2] = { "외쪽", "오른쪽" };
	static int directionPoint;
};

class DuckingState : public HeroState {
	void inputHandle(class player& p, int input) override;
	void update(class player& p) override;
	void render() override;
};

class StandingState : public HeroState {
	void inputHandle(class player& p, int input) override;
	void update(class player& p) override;
	void render() override;
};

class JumpingState : public HeroState {
	void inputHandle(class player& p, int input) override;
	void update(class player& p) override;
	void render() override;
};



