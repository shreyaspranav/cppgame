#include "GameApplication.h"
#include "Log.h"
#include <string>

#include <core/graphics/window/Window.h>
#include <core/event/KeyEvent.h>

namespace cppgame {

	std::unique_ptr<Window> window;
	inline const std::string BoolToString(bool b)
	{
		return b ? "true" : "false";
	}

	GameApplication::GameApplication()
	{
		OnCreate();
		OnStart();

		for (;;) { OnUpdate(0.0f); }

		
		OnExit();
	}
	GameApplication::~GameApplication()
	{

	}

	void GameApplication::OnEvent(Event& event)
	{
		LOG_INFO(event.ToString());
		if (event.GetEventType() == EventType::WindowClose) { exit(0); }
	}
	
	void GameApplication::OnCreate()
	{
		INIT_LOGGER;

		WindowData data;
		window = std::unique_ptr<Window>(Window::GetWindow(data));
		window->WindowCreate();
		window->SetEventCallbacks(std::bind(&cppgame::GameApplication::OnEvent, this, std::placeholders::_1));
		window->SetWindowIcon("icon.png");
		LOG_ERROR_SEVERE("Test");
	}
	void GameApplication::OnStart()
	{
	}
	void GameApplication::OnUpdate(float interval)
	{
		window->WindowUpdate();
	}
	void GameApplication::OnExit()
	{

	}
	
}

