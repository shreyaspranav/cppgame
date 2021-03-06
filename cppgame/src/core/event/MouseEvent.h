#pragma once

#include <core/app/Core.h>
#include <sstream>
#include <core/app/KeyCodes.h>
#include <core/event/Event.h>

namespace cppgame
{
	class MouseMovedEvent : public Event
	{
	private:
		double xpos, ypos;
	public:
		MouseMovedEvent(double x, double y) : xpos(x), ypos(y) {}

		inline double GetX(){ return xpos; }
		inline double GetY(){ return ypos; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "Mouse Moved: X:" << xpos << ", Y:" << ypos;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseMoved)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};

	class MouseButtonPressedEvent : public Event
	{
	private:
		KeyCode code;
		double xpos, ypos;
		bool repeat;
	public:
		MouseButtonPressedEvent(KeyCode code, bool repeat, double x, double y):code(code), repeat(repeat), xpos(x), ypos(y){}

		inline double GetX() { return xpos; }
		inline double GetY() { return ypos; }

		inline KeyCode GetKey() { return code; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Clicked: Button: "<< (int)code <<" X:" << xpos << ", Y : " << ypos << " Repeat: " << repeat;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseButtonPressed)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};

	class MouseButtonReleasedEvent : public Event
	{
	private:
		KeyCode code;
		double xpos, ypos;
	public:
		MouseButtonReleasedEvent(KeyCode code, double x, double y) :code(code), xpos(x), ypos(y) {}

		inline double GetX() { return xpos; }
		inline double GetY() { return ypos; }

		inline KeyCode GetKey() { return code; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: Button: " << (int)code << " X:" << xpos << ", Y: " << ypos;
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseButtonReleased)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};

	class MouseScrolledEvent : public Event
	{
	public:
		enum ScrollDir { SCROLL_UP = 1, SCROLL_DOWN = -1 };

		MouseScrolledEvent(ScrollDir dir): dir(dir)  {}

		inline ScrollDir getScrollDir() { return dir; }

		std::string ToString() const override
		{
			std::stringstream ss;

			if (dir == ScrollDir::SCROLL_UP) {
				ss << "Scrolled: UP";
			}

			else if (dir == ScrollDir::SCROLL_DOWN) {
				ss << "Scrolled: DOWN";
			}
			
			return ss.str();
		}

		DEFINE_EVENT_CLASS_TYPE(MouseScrolled)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		ScrollDir dir;
	};

	class MouseEnteredEvent : public Event
	{
	public:
		MouseEnteredEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(MouseEntered)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};

	class MouseExitedEvent : public Event
	{
	public:
		MouseExitedEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(MouseExited)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};
}