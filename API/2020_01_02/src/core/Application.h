#pragma once
#include "WindowApiLib/ApplicationCore.h"

class Application : public ApplicationCore {
public:
	virtual bool init(const HINSTANCE& hInst, int nCmdShow);

private:
	virtual void Logic();
	void update();
	void render();

private:
	DECLARE_SINGLE(Application)

};

