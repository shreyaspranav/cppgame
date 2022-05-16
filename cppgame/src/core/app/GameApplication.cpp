#include "GameApplication.h"
#include "Log.h"
#include <string>

#include <GLFW/glfw3.h>

namespace cppgame {

	inline const std::string BoolToString(bool b)
	{
		return b ? "true" : "false";
	}

	GameApplication::GameApplication()
	{
		OnCreate();
		OnStart();

	    OnUpdate(0.0f);

		
		OnExit();
	}
	GameApplication::~GameApplication()
	{

	}
	void GameApplication::OnCreate()
	{
	}
	void GameApplication::OnStart()
	{
	}
	void GameApplication::OnUpdate(float interval)
	{
		LOG_COLOR_TEST;
		LOG_INFO(BoolToString(glfwInit()));
	}
	void GameApplication::OnExit()
	{

	}
}

