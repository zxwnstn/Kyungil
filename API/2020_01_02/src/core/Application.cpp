#include "Application.h"

DEFINITION_SINGLE(Application)


Application::Application()
{
}


Application::~Application()
{
}


bool Application::init(const HINSTANCE & hInst, int nCmdShow)
{
	if (!ApplicationCore::init(hInst, nCmdShow))
		return false;
	return true;
}

void Application::Logic()
{
	update();
	render();
}

void Application::update()
{
	ApplicationCore::update();

	GET_SINGLE(SceneManager)->update(m_fDeltaTime);
	GET_SINGLE(CollisionManager)->update();
}

void Application::render()
{
	GET_SINGLE(SceneManager)->render();
}
