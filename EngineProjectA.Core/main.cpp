#include <iostream>
#include "src/Graphics/Window.h"


int main(void) {
	using namespace Engine;
	using namespace Graphics;

	Window window("Engine", 1366, 768);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.Closed()) {
		window.Clear();

		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
		window.Update();
	}

	window.~Window();

	return 0;
}