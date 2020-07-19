#include "Window.h"
#include <iostream>

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

			for (int i = 0; i < MAX_KEYS; i++)
				_keys[i] = false;

			for (int i = 0; i < MAX_BUTTONS; i++)
				_mouseButtons[i] = false;
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::IsKeyPressed(unsigned int keyCode) const
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return _keys[keyCode];
		}

		bool Window::IsMouseButtonPressed(unsigned int button) const
		{
			if (button >= MAX_BUTTONS)
				return false;

			return _mouseButtons[button];
		}

		void Window::GetMousePosition(double& x, double& y) const
		{
			x = _x;
			y = _y;
		}

		void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->_keys[key] = action != GLFW_RELEASE;
		}

		void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void CursourPositionCallback(GLFWwindow* window, double x, double y)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->_x = x;
			win->_y = y;
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
			glfwSetWindowUserPointer(_window, this);
			glfwSetWindowSizeCallback(_window, WindowResize);
			glfwSetKeyCallback(_window, KeyCallback);
			glfwSetMouseButtonCallback(_window, MouseButtonCallback);
			glfwSetCursorPosCallback(_window, CursourPositionCallback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;
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

		void WindowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}		
	}
}
