#pragma once

#include <GL/glew.h> 
#include <GLFW/glfw3.h>


namespace Engine {
	namespace Graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window
		{

		private:
			friend struct GLFWwindow;

			const char* _title;
			int _width, _heigth;
			GLFWwindow* _window;
			bool _closed;

			bool _keys[MAX_KEYS];
			bool _mouseButtons[MAX_BUTTONS];
			double _x, _y;
		public:
			Window(const char* title, int width, int heigth);
			~Window();

			void Clear() const;
			void Update();
			bool Closed() const;

			int GetWidth() const { return _width; }
			int GetHeight() const { return _heigth; }

			bool IsKeyPressed(unsigned int keyCode) const;
			bool IsMouseButtonPressed(unsigned int button) const;
			void GetMousePosition(double& x, double& y) const;
		private:
			friend static void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
			friend static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			friend static void CursourPositionCallback(GLFWwindow* window, double x, double y);
			bool Init();

		};
	}
}

