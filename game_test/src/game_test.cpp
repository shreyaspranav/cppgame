#include <iostream>
#include <cppgame.h>


class game_test : public cppgame::GameApplication
{

public:

	game_test() { }
	virtual ~game_test(){}

	void OnCreate() override
	{
		LOG_ERROR("Phuc!");
		width = 720;
	}

	void OnStart() override
	{
	}

	void OnUpdate(float interval) override
	{
	}

	void OnExit() override
	{
	}

};

void main()
{
	cppgame::GameApplication* app = new game_test();
	app->Run();
	delete app;
	std::cout << "Hello cppgame!" << std::endl;
}