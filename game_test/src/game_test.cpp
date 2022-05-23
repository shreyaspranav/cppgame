#include <iostream>
#include <cppgame.h>
#include <chrono>


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

	}
	virtual void OnRender(cppgame::Renderer r) override {}
};

class game_test : public cppgame::GameApplication
{

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
;
	}

	void OnRender(cppgame::Renderer r) override
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