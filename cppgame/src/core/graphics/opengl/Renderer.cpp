#include "Renderer.h"

#include <glad/glad.h>
#include <core/app/Core.h>
#include <core/app/Log.h>

namespace cppgame
{
	Renderer::Renderer(GLFWwindow* window) : window(window)
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::CreateContext()
	{
		glfwMakeContextCurrent(window);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LOG_ERROR_SEVERE("Glad Failed to Initialise!");
		}

		glfwSwapInterval(0);

		LOG_INFO("GPU INFO:");
		LOG_INFO(glGetString(GL_VENDOR));
		LOG_INFO(glGetString(GL_RENDERER));
		LOG_INFO("OpenGL: {0}", glGetString(GL_VERSION));
		LOG_INFO("GLSL: {0}", glGetString(GL_SHADING_LANGUAGE_VERSION));
	}

	void Renderer::RenderClear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2, 0.2, 0.2, 1.0);
	}

}
