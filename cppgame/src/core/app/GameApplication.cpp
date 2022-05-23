#include "GameApplication.h"
#include "Log.h"
#include <string>

#include <core/graphics/window/Window.h>
#include <core/event/KeyEvent.h>

namespace cppgame {

	std::unique_ptr<Window> window;

	GameApplication::GameApplication()
	{
		INIT_LOGGER;
	}
	GameApplication::~GameApplication()
	{

	}

	void GameApplication::OnEvent(Event& event)
	{
		LOG_TRACE(event.ToString());
		if (event.GetEventType() == EventType::WindowClose) { 
			for (int i = 1; i <= stack.size(); i++) { stack[i - 1]->OnDetach(); }
			exit(0); 
		}
	}
	
	void GameApplication::OnCreate()
	{
		OnCreate();
	}
	void GameApplication::OnStart()
	{
		OnStart();

		if (fullscreen == 0) {
			WindowData data(window_width, window_height, window_title, 0, vsync);

			window = std::unique_ptr<Window>(Window::GetWindow(data));
			window->WindowCreate();
		}

		else {
			WindowData data(window_width, window_height, window_title, 0, vsync);

			window = std::unique_ptr<Window>(Window::GetWindow(data));
			window->WindowCreate();
			window->SetFullScreen(fullscreen);
		}
		

		window->SetEventCallbacks(std::bind(&cppgame::GameApplication::OnEvent, this, std::placeholders::_1));
		window->SetWindowIcon("icon.png");

		r = Renderer(window->GetRawWindowPointer());
		r.CreateContext();
	}

	void GameApplication::OnInput()
	{
		OnInput();
		for (int i = 1; i <= stack.size(); i++){ stack[i - 1]->OnInput(); }
	}

	void GameApplication::OnRender(Renderer r)
	{
		r.RenderClear();
		OnRender(r);
		for (int i = 1; i <= stack.size(); i++) { stack[i - 1]->OnRender(r); }
	}

	void GameApplication::OnUpdate(double interval)
	{
		OnUpdate(interval);
		for (int i = 1; i <= stack.size(); i++) { stack[i - 1]->OnUpdate(interval); }
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
			GameApplication::OnRender(r);

			lastTime = current;
		}

		GameApplication::OnExit();

	}

	void GameApplication::PushLayer(Layer* l)
	{
		stack.push_back(l);
		l->OnAttach();
	}

	void GameApplication::PopLayer()
	{
		stack.pop_back();
		stack.back()->OnDetach();
	}
}

