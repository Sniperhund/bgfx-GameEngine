#include "Stats.h"

#include <imgui.h>
#include <bgfx/bgfx.h>

void Stats::Update()
{
    ImGui::Text("Renderer: %s", bgfx::getRendererName(bgfx::getRendererType()));
}

void Stats::Start()
{
    Title = "Stats";
}
