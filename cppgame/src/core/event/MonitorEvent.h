#pragma once

#include "Event.h"

namespace cppgame {
	class MonitorConnectedEvent : public Event
	{
	public:
		MonitorConnectedEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(MonitorConnect)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategorySystem)
	};

	class MonitorDisconnectedEvent : public Event
	{
	public:
		MonitorDisconnectedEvent() = default;

		DEFINE_EVENT_CLASS_TYPE(MonitorDisconnect)
		DEFINE_EVENT_CLASS_CATEGORY(EventCategorySystem)
	};
}