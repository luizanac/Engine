#include <iostream>
#include "src/Graphics/Window.h"


int main(void) {
	using namespace Engine;
	using namespace Graphics;

	Window window("Engine", 1366, 768);


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed()) {
		window.Clear();

		if(window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "'Mouse' pressed!" << std::endl;

		double x, y;
		window.GetMousePosition(x, y);
		std::cout << "x: " << x << "y: " << y << std::endl;

		glBegin(GL_TRIANGLES);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.Update();
	}

	window.~Window();
	
	return 0;
}