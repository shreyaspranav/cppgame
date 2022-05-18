#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <functional>

#include <core/event/Event.h>

namespace cppgame {

	using EventCallbackFn = std::function<void(Event&)>;

	struct WindowData {
		unsigned int window_width, window_height;
		std::string window_title;
		bool fullscreen, vsync;
		EventCallbackFn fn;

		WindowData(unsigned int width = 1600,
					unsigned int height = 900,
					std::string title = "cppgame",
					bool fullscreen = 0, bool vsync = 0): window_width(width), window_height(height), window_title(title),
												fullscreen(fullscreen), vsync() {}
	};

	struct MonitorData {
		GLFWmonitor** monitors;
		int count;
		EventCallbackFn fn;
	};

	class Window
	{
	private:
		WindowData m_data;
		MonitorData mon_data;

		GLFWwindow* m_window;
		Window(WindowData& data);

	public:
		~Window();

		static Window* GetWindow(WindowData& data);

		void SetEventCallbacks(EventCallbackFn fn);
		inline EventCallbackFn GetEventCallbackFn();

		void WindowCreate();
		void WindowUpdate();
		void WindowDestroy();

		unsigned int GetWidth();
		unsigned int GetHeight();
		std::string GetTitle();

		bool IsVsync();
		bool IsFullScreen();

		void SetWidth(unsigned int width);
		void SetHeight(unsigned int height);
		void SetTitle(std::string title);

		inline void SetVsync(bool vsync);
		void SetFullScreen(unsigned int monitor);
		void SetWindowed();

	};
}

