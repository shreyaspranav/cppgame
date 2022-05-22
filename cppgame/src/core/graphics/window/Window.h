#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include <core/app/KeyCodes.h>
#include <core/event/Event.h>

namespace cppgame {

	using EventCallbackFn = std::function<void(Event&)>;

	struct WindowData {
		unsigned int window_width, window_height;
		std::string window_title;

		bool fullscreen, vsync;
		EventCallbackFn fn;

		WindowData(unsigned int width = 1280,
					unsigned int height = 720,
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
		inline static GLFWwindow* w;
		Window(WindowData& data);

	public:
		~Window();

		static Window* GetWindow(WindowData& data);

		void SetEventCallbacks(EventCallbackFn fn);
		inline EventCallbackFn GetEventCallbackFn() { return m_data.fn; }

		void WindowCreate();
		void WindowUpdate();
		void WindowDestroy();

		inline unsigned int GetWidth() { return m_data.window_width; }
		inline unsigned int GetHeight() { return m_data.window_height; }
		inline std::string GetTitle() { return m_data.window_title; }

		inline bool IsVsync() { return m_data.vsync; }
		bool IsFullScreen();

		void SetWidth(unsigned int width);
		void SetHeight(unsigned int height);
		void SetTitle(std::string title);

		void SetVsync(bool vsync);
		void SetFullScreen(unsigned int monitor);
		void SetWindowed();

		void SetWindowIcon(std::string path);

		inline static GLFWwindow* GetRawWindowPointer() { return w; }
	};

	class Input {
	public:
		static bool IsKeyPressed(KeyCode k);
		static double GetMouseX();
		static double GetMouseY();
	};
}

