#include <iostream>
#include <cppgame.h>


class game_test : public cppgame::GameApplication
{

public:

	cppgame::GameApplication* appl;

	game_test() { appl = new cppgame::GameApplication(); }
	virtual ~game_test(){}

	void OnCreate() override
	{
		cppgame::GameApplication::OnCreate();
	}

	void OnStart() override
	{
		cppgame::GameApplication::OnStart();
	}

	void OnUpdate(float interval) override
	{
		cppgame::GameApplication::OnUpdate(interval);
	}

	void OnExit() override
	{
		cppgame::GameApplication::OnExit();
	}

};

void main()
{
	game_test* app = new game_test();
	delete app->appl;
	delete app;
	std::cout << "Hello cppgame!" << std::endl;
}