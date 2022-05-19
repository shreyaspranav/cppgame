#include "Window.h"
#include "core/app/Log.h"

#include <core/event/WindowEvent.h>
#include <core/event/KeyEvent.h>
#include <core/event/MouseEvent.h>
#include <core/event/MonitorEvent.h>

namespace cppgame
{
	Window::Window(WindowData& data)
	{
		m_data.window_width = data.window_width;
		m_data.window_height = data.window_height;
		m_data.window_title = data.window_title;
		m_data.fullscreen = data.fullscreen;
		m_data.vsync = data.vsync;

		if (!glfwInit()) {
			LOG_ERROR_SEVERE("GLFW failed to initialise!");
			exit(-1);
		}

		std::string s = glfwGetVersionString();
		LOG_INFO("GLFW version: " + s);
	}
	Window::~Window()
	{
		Window::WindowDestroy();
	}
	Window* Window::GetWindow(WindowData& data)
	{
		return new Window(data);
	}
	void Window::SetEventCallbacks(EventCallbackFn fn)
	{
		m_data.fn = fn;
		mon_data.fn = fn;

		/*
		* List of Event Callbacks implemtented:
		* 
		* -> WindowEvents:
		*	1. ErrorCallback
		*	2. WindowCloseCallback
		*	3. WindowFocusCallback
		*	4. WindowResizeCallback
		*	5. WindowMovedCallback
		* 
		* -> KeyEvents:
		*	1. KeyPressedEvent
		*	2. KeyReleasedEvent
		* 
		* -> MouseEvents
		*	1. MouseMovedEvent
		*	2. MouseButtonPressedEvent
		*	3. MouseButtonReleasedEvent
		*	4. MouseScrolledEvent
		*	5. MouseEnteredEvent
		*	6. MouseExitedEvent
		* 
		* -> MonitorEvents
		*	1. MonitorConnected
		*	2. MonitorDisconnected
		*/

		// Window Events:
		glfwSetErrorCallback([](int error_code, const char* description) 
		{
			std::string des = description;
			LOG_ERROR("GLFW Error: " + error_code);
			LOG_ERROR(des);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent windowCloseEvent;
			data.fn(windowCloseEvent);

			glfwDestroyWindow(window);
		});

		glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int iconified)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (iconified == GLFW_TRUE) {
				WindowFocusEvent eve;
				data.fn(eve);
			}

			else if (iconified == GLFW_FALSE) {
				WindowLostFocusEvent eve;
				data.fn(eve);
			}
		});
		
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			data.window_height = width;
			data.window_height = height;

			WindowResizeEvent evt(width, height);
			data.fn(evt);
		});

		glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xpos, int ypos) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowMovedEvent evt(xpos, ypos);
			data.fn(evt);
		});

		//KeyEvents:
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (action == GLFW_PRESS)
			{
				KeyPressedEvent evt((KeyCode)key, 0); //Repeat = 0
				data.fn(evt);
			}

			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent evt((KeyCode)key);
				data.fn(evt);
			}

			if (action == GLFW_REPEAT)
			{
				KeyPressedEvent evt((KeyCode)key, 1); //Repeat = 1
				data.fn(evt);
			}
		});

		//MouseEvents:
		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent evt(xpos, ypos);
			data.fn(evt);
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (action == GLFW_PRESS)
			{
				double x, y;
				glfwGetCursorPos(window, &x, &y);

				MouseButtonPressedEvent evt((KeyCode)button, 0, x, y); //Repeat = 0
				data.fn(evt);
			}

			else if (action == GLFW_RELEASE)
			{
				double x, y;
				glfwGetCursorPos(window, &x, &y);

				MouseButtonReleasedEvent evt((KeyCode)button, x, y);
				data.fn(evt);
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent evt((MouseScrolledEvent::ScrollDir)yoffset);
			data.fn(evt);
		});

		glfwSetCursorEnterCallback(m_window, [](GLFWwindow* window, int entered)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (entered == GLFW_TRUE)
			{
				MouseEnteredEvent evt;
				data.fn(evt);
			}

			if (entered == GLFW_FALSE)
			{
				MouseExitedEvent evt;
				data.fn(evt);
			}
		});

		// Monitor Callbacks
		glfwSetMonitorCallback([](GLFWmonitor* monitor, int event) 
		{
			if (event == GLFW_CONNECTED) {
				MonitorData& data = *(MonitorData*)glfwGetMonitorUserPointer(glfwGetPrimaryMonitor());
				data.monitors = glfwGetMonitors(&data.count);

				MonitorConnectedEvent evt;
				data.fn(evt);

				std::stringstream ss;
				ss << "No of Monitors: " << data.count;
				LOG_WARN(ss.str());
			}

			if (event == GLFW_DISCONNECTED) {
				MonitorData& data = *(MonitorData*)glfwGetMonitorUserPointer(glfwGetPrimaryMonitor());
				data.monitors = glfwGetMonitors(&data.count);

				MonitorConnectedEvent evt;
				data.fn(evt);

				std::stringstream ss;
				ss << "No of Monitors: " << data.count;
				LOG_WARN(ss.str());
			}
		});

	}
	EventCallbackFn Window::GetEventCallbackFn()
	{
		return EventCallbackFn();
	}
	void Window::WindowCreate()
	{
		if(m_data.fullscreen){
			// TODO: Add multimonitor fullscreen support 
			m_window = glfwCreateWindow(m_data.window_width, m_data.window_height, m_data.window_title.c_str(), glfwGetPrimaryMonitor(), NULL);
		}

		else
			m_window = glfwCreateWindow(m_data.window_width, m_data.window_height, m_data.window_title.c_str(), NULL, NULL);

		if (!m_window)
		{
			Window::WindowDestroy();
			LOG_ERROR_SEVERE("Failed to create a GLFW window!");
		}

		mon_data.monitors = glfwGetMonitors(&mon_data.count);
		
		glfwSetWindowUserPointer(m_window, &m_data);
		glfwSetMonitorUserPointer(glfwGetPrimaryMonitor(), &mon_data);

		glfwShowWindow(m_window);
	}
	void Window::WindowUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	void Window::WindowDestroy()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::SetFullScreen(unsigned int monitor)
	{
		if (mon_data.count >= monitor)
			glfwSetWindowMonitor(m_window, mon_data.monitors[monitor - 1], 0, 0, m_data.window_width, m_data.window_height, GLFW_DONT_CARE);
		else
		{
			std::stringstream ss;
			ss << "Monitor No " << monitor << " not found!";
			LOG_ERROR(ss.str());
		}
	}

	void Window::SetWindowed()
	{
		glfwSetWindowMonitor(m_window, NULL, 0, 0, m_data.window_width, m_data.window_height, GLFW_DONT_CARE);
	}

    unsigned int Window::GetWidth()
	{
		return 0;
	}
	unsigned int Window::GetHeight()
	{
		return 0;
	}
	std::string Window::GetTitle()
	{
		return std::string();
	}
	bool Window::IsVsync()
	{
		return false;
	}
	bool Window::IsFullScreen()
	{
		return false;
	}
	void Window::SetWidth(unsigned int width)
	{
	}
	void Window::SetHeight(unsigned int height)
	{
	}
	void Window::SetTitle(std::string title)
	{
	}
	void Window::SetVsync(bool vsync)
	{
	}
	
}