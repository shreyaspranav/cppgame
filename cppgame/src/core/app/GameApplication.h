#pragma once
#include "Core.h"

#include <core/event/Event.h>
#include <vector>
#include "Layer.h"

namespace cppgame
{
	class CPPGAME_API GameApplication {

		using LayerStack = std::vector<Layer*>;
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

		void PushLayer(Layer* l);
		void PopLayer();

		unsigned int window_width = 1280, window_height = 720;
		std::string window_title = "cppgame";
		bool vsync = 0;
		unsigned int fullscreen = 0;

	private:
		LayerStack stack;
	};
}