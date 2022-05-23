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
		INIT_LOGGER;
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
		OnCreate();
	}
	void GameApplication::OnStart()
	{
		OnStart();

		LOG_INFO(width);
		WindowData data(width, height, title, fullscreen, vsync);

		window = std::unique_ptr<Window>(Window::GetWindow(data));
		window->WindowCreate();

		window->SetEventCallbacks(std::bind(&cppgame::GameApplication::OnEvent, this, std::placeholders::_1));
		window->SetWindowIcon("icon.png");

		LOG_ERROR_SEVERE("Test");
	}

	void GameApplication::OnInput()
	{
		OnInput();
	}

	void GameApplication::OnRender()
	{
		OnRender();
	}

	void GameApplication::OnUpdate(double interval)
	{
		OnUpdate(interval);
		window->WindowUpdate();
	}
	void GameApplication::OnExit()
	{
		OnExit();
	}
	
	void GameApplication::Run() {
		GameApplication::OnCreate();
		GameApplication::OnStart();

		double lastTime = window->GetUpTime();
		while (true)
		{
			double current = window->GetUpTime();
			double elapsed = current - lastTime;

			GameApplication::OnInput();
			GameApplication::OnUpdate(elapsed); 
			GameApplication::OnRender();

			lastTime = current;

			LOG_INFO(elapsed);
		}

		GameApplication::OnExit();

		

	}
}

