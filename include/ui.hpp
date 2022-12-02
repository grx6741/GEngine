#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace base {
	namespace ui {
		class Ui {
			public:
				Ui();
				void frameInit();
				void frameEnd();
				void fpsCounter();
				~Ui();
				void Init(GLFWwindow* window);
				void quit();
				
		};
	
	}

}
