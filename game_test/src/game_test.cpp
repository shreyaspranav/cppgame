#include <iostream>
#include <cppgame.h>
#include <chrono>


class game_test : public cppgame::GameApplication
{

class TestLayer : public cppgame::Layer
{

public:

	TestLayer() {

	}

	virtual void OnAttach() override {
		LOG_WARN("Layer Attached!");
	}
	virtual void OnDetach()override {
		LOG_WARN("Layer Dettached!");
	}

	virtual void OnInput() override {

	}
	virtual void OnUpdate(double timestep) override {
		LOG_WARN("FPS: {0}", 1.0 / timestep);
	}
	virtual void OnRender() override {}
};

public:

	game_test() { }
	virtual ~game_test(){}

	void OnCreate() override
	{
		window_title = "Game Window";
		PushLayer(new TestLayer());
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