#pragma once

#include <core/app/Core.h>
#include <GLFW/glfw3.h>

namespace cppgame{

	class CPPGAME_API Renderer
	{
	private:
		GLFWwindow* window;

	public:
		Renderer(){}
		Renderer(GLFWwindow* window);
		~Renderer();

		void CreateContext();
		void RenderClear();
	};

}


