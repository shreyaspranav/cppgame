#pragma once
#include "Core.h"

namespace cppgame
{
	class CPPGAME_API GameApplication {

	public:

		GameApplication();
		virtual ~GameApplication();

		virtual void OnCreate();
		virtual void OnStart();
		virtual void OnUpdate(float interval);
		virtual void OnExit();
	};
}