#include "UI_Widget.h"

#include <imgui.h>

void UI_Widget::Internal_Update()
{
    if (!Active) return;

    if (!ImGui::Begin(Title.c_str(), &Active, NULL))
    {
        ImGui::End();
        return;
    }

    Update();

    ImGui::End();
}

void UI_Widget::Internal_Start()
{
    Start();
}