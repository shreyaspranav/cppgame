#pragma once

#include <core/event/Event.h>
#include <sstream>

namespace cppgame {

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowClose)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowFocus)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(WindowLostFocus)
			DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int width, height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
			: width(width), height(height) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		DEFINE_EVENT_CLASS_TYPE(WindowResize)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)
		
		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "Window Resize Event: " << width << ", " << height;
			return ss.str();
		}

	};

	class WindowMovedEvent :public Event
	{
	private:
		unsigned int x_pos, y_pos;

	public:
		WindowMovedEvent(unsigned int xpos, unsigned int ypos)
			:x_pos(xpos), y_pos(ypos){}

		inline unsigned int GetXPos() const { return x_pos; }
		inline unsigned int GetYPos() const { return y_pos; }

		DEFINE_EVENT_CLASS_TYPE(WindowMoved)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategoryApplication)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Moved Event: " << x_pos << ", " << y_pos;
			return ss.str();
		}
	};
}