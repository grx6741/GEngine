#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ui.hpp"

namespace base {
	namespace graphics {
		class Window {
			private:
				int _width;
				int _height;
				const char* _title;
				GLFWwindow* _window;
				base::ui::Ui ui;

			public:
				Window(int width, int height, const char* title);
				~Window();
				void run();
			private:
				void Init();
				void update();
				static void errorCall(int error, const char* description);
				static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
				static void window_callback(GLFWwindow* window, int width, int height);
				void quit();
		};
	};
};
