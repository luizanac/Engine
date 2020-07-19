#pragma once

#include <GLFW/glfw3.h>

namespace Engine {
	namespace Graphics {

		class Window
		{
		private:
				const char* _title;
				int _width, _heigth;
				GLFWwindow* _window;
				bool _closed;

		public:
			Window(const char* title, int width, int heigth);
			~Window();

			void Clear() const;
			void Update();
			bool Closed() const;

			int getWidth() const { return _width; }
			int getHeight() const { return _heigth; }

		private:
			bool Init();

		};
	}
}

