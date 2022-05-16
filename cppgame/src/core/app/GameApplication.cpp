#include "GameApplication.h"
#include "Log.h"
#include <string>

namespace cppgame {

	Log l;

	inline const std::string BoolToString(bool b)
	{
		return b ? "true" : "false";
	}

	GameApplication::GameApplication()
	{
		OnCreate();
		OnStart();

	    OnUpdate(0.0f);

		
		OnExit();
	}
	GameApplication::~GameApplication()
	{

	}
	void GameApplication::OnCreate()
	{
	}
	void GameApplication::OnStart()
	{
	}
	void GameApplication::OnUpdate(float interval)
	{
		l.ErrorSevere("Idol Idol");
	}
	void GameApplication::OnExit()
	{
	}

	

}

