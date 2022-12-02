#include "base.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace base {
	namespace graphics {
		Window::Window(int width, int height, const char* title) {	
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			_width = width;
			_height = height;
			_title = title;
			Window::Init();
		}

		void Window::Init() {
			if (!glfwInit()) {
				Window::quit();
			}
			_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

			if (! _window) {
				Window::quit();
			}

			glfwMakeContextCurrent(_window);

			if ( glewInit() != GLEW_OK ) {
				std::cout << "Can't initialize glew\n";
				Window::quit();
			}

			Window::ui.Init(_window);
		}

		void Window::update() {
			ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

			while (! glfwWindowShouldClose(_window)) {

				Window::ui.frameInit();

				glfwSetErrorCallback(Window::errorCall);
				glfwSetKeyCallback(_window, Window::key_callback);
				glfwSetWindowSizeCallback(_window, Window::window_callback);

				Window::ui.fpsCounter();

        			glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
				glClear(GL_COLOR_BUFFER_BIT);

				Window::ui.frameEnd();

				glfwSwapBuffers(_window);
				glfwPollEvents();
			}
		}

		void Window::run() {
			Window::update();
		}

		void Window::errorCall(int error, const char* description) {
			std::cerr << "[Error] " << description << std::endl;
		}

		void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}
		}
		void Window::window_callback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}


		void Window::quit() {
			Window::ui.quit();
			glfwDestroyWindow(_window);
			glfwTerminate();
		}

		Window::~Window() {
			Window::quit();
		}
	}
}
