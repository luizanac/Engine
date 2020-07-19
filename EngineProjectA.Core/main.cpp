#include <iostream>
#include "src/Graphics/Window.h"

using namespace Engine;
using namespace Graphics;
#define INITIAL_WIDTH 1024
#define INITIAL_HEIGHT 600
int main(void) {


	Window* window = new Window("Engine", INITIAL_WIDTH, INITIAL_HEIGHT);
	/*for (int i = 0; i < window->GetHeight(); i++)
		for (int j = 0; j < window->GetWidth(); j++)
		{
			pixels[(j + window->GetWidth() * i) * 3 + 0] = 1.0f;
			pixels[(j + window->GetWidth() * i) * 3 + 1] = 0.0f;
			pixels[(j + window->GetWidth() * i) * 3 + 2] = 0.0f;
		}*/


	static int i = 0;
	static int j = 0;
	while (!window->Closed()) {
		window->Clear();

		double x, y;
		window->GetMousePosition(x, y);
		std::cout << "x: " << x << "y: " << y << std::endl;
		float* pixels = new float[(int)(window->GetWidth() * window->GetHeight() * 3)]();
		if (window->IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			pixels[(int)((window->GetWidth() - x) * (window->GetHeight() - y)) * 3 + 0] = 0.0f;
			pixels[(int)((window->GetWidth() - x) * (window->GetHeight() - y)) * 3 + 1] = 0.0f;
			pixels[(int)((window->GetWidth() - x) * (window->GetHeight() - y)) * 3 + 2] = 1.0f;
		}

		glDrawPixels(window->GetWidth(), window->GetHeight(), GL_RGB, GL_FLOAT, pixels);

		window->Update();
		delete[] pixels;

	}
	window->~Window();

	return 0;
}