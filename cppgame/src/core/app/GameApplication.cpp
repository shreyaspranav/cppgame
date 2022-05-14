#include "GameApplication.h"
#include "Log.h"


namespace cppgame {

	Log l;

	GameApplication::GameApplication()
	{
		OnCreate();
		OnStart();

		for(;;){ OnUpdate(0.0f); }

		
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
		l.ErrorSevere("fjsdaj;lk");
	}
	void GameApplication::OnExit()
	{
	}

}

