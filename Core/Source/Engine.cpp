#include "Engine.h"

#include <imgui.h>
#include <imgui_impl_bgfx.h>

#include "backends/imgui_impl_glfw.h"
#include "Graphics/Renderer.h"

std::vector<UI_Widget*> Engine::m_UI_Widgets;

void Engine::Start()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui_Implbgfx_Init(255);
    ImGui_ImplGlfw_InitForOther(Renderer::GetGLFWWindow(), true);
}

void Engine::Update()
{
    Renderer::RenderFrame();

    ImGui_Implbgfx_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("Windows"))
    {
        for (auto& layer : m_UI_Widgets)
        {
            if (ImGui::MenuItem(layer->Title.c_str(), nullptr, layer->Active)) layer->Active = !layer->Active;
        }
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
    
    for (const auto widget : m_UI_Widgets)
    {
        widget->Internal_Update();
    }
    
    ImGui::Render();
    ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());
}

void Engine::AddUIWidget(UI_Widget* widget)
{
    m_UI_Widgets.push_back(widget);
    widget->Internal_Start();
}
