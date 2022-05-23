#include <iostream>
#include <cppgame.h>
#include <chrono>


class game_test : public cppgame::GameApplication
{

public:

	game_test() { }
	virtual ~game_test(){}

	void OnCreate() override
	{
		LOG_ERROR("Phuc!");
	}

	void OnStart() override
	{
	}

	void OnInput() override
	{

	}

	void OnUpdate(double interval) override
	{

		if(cppgame::Input::IsKeyPressed(cppgame::KeyCode::KEYPAD_1))
			LOG_ERROR("Phuc!");
	}

	void OnRender() override
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