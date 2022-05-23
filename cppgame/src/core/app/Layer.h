#pragma once

#include "Core.h"
#include <string>
#include <core/event/Event.h>

namespace cppgame {
	class CPPGAME_API Layer
	{
	public:
		Layer() {}
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnInput() {}
		virtual void OnUpdate(double timestep) {}
		virtual void OnRender() {}

		virtual void OnEvent(Event& event) {}

		virtual unsigned int GetIndex() { return index; }
	protected:
		unsigned int index;
	};
}