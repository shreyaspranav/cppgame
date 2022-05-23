#pragma once
#include "Core.h"

#include <core/event/Event.h>

namespace cppgame
{
	class CPPGAME_API GameApplication {

	public:

		GameApplication();
		virtual ~GameApplication();

		virtual void OnCreate();
		virtual void OnStart();

		virtual void OnInput();
		virtual void OnUpdate(double interval);
		virtual void OnRender();

		virtual void OnExit();

		void Run();

		virtual void OnEvent(Event& event);

		unsigned int width = 1280, height = 720;
		std::string title = "cppgame";
		bool vsync = 0, fullscreen = 0;
	};
}