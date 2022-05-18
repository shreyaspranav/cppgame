#pragma once

#include <core/app/Core.h>
#include <string>

namespace cppgame
{
	enum class EventType
	{
		None = 0,

		// Monitor Events:
		MonitorConnect, MonitorDisconnect,

		// Window Events:
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,

		// App Events: TODO: Implement them asap
		AppFixedUpdate, AppUpdate,

		// Key Events:
		KeyPressed, KeyReleased,

		// Mouse Events:
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled, MouseEntered, MouseExited
	};

	enum EventCategory
	{
		None = 0,
		EventCategorySystem			 = BIT(0),
		EventCategoryApplication	 = BIT(1),
		EventCategoryInput			 = BIT(2),
		EventCategoryKeyBoard		 = BIT(3),
		EventCategoryMouse			 = BIT(4),
		EventCategoryMouseButton	 = BIT(5)
	};

	#define DEFINE_EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }  \
										  virtual EventType GetEventType() const override { return GetStaticType(); }  \
										  virtual std::string GetName() const override { return #type; }

	#define DEFINE_EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class CPPGAME_API Event
	{
	public:
		bool event_handled = 0;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory cat) { return GetCategoryFlags() & cat; }
	};
}