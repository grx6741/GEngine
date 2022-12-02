#include "ui.hpp"
#include "imgui/imgui.h"

namespace base {
	namespace ui {
		Ui::Ui() {

		}

		void Ui::frameInit() {
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
		}

		void Ui::frameEnd() {
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}

		void Ui::fpsCounter() {
        		ImGui::Begin(" ");
        		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        		ImGui::End();

		}

		void Ui::Init(GLFWwindow* window) {
			ImGui::CreateContext();
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init();
			ImGui::StyleColorsDark();
		}

		void Ui::quit() {
    			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext();
		}

		Ui::~Ui() {
			//Ui::quit();
		}
	}

}
