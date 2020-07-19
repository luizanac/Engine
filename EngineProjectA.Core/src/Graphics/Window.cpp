#include "Window.h"
#include <iostream>
#include <GLFW/glfw3.h>


namespace Engine {
	namespace Graphics {

		void WindowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int heigth)
		{
			_title = title;
			_width = width;
			_heigth = heigth;

			if (!Init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::Init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			_window = glfwCreateWindow(_width, _heigth, _title, NULL, NULL);
			if (!_window) {
				glfwTerminate();
				std::cout << "Failed to create GLFW Window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(_window);
			glfwSetWindowSizeCallback(_window, WindowResize);

			return true;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(_window, &_width, &_heigth);
			glfwSwapBuffers(_window);
		}

		bool Window::Closed() const {
			return glfwWindowShouldClose(_window) == 1;
		}

		void WindowResize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}
