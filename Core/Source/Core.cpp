#include <memory>
#include <bgfx/bgfx.h>
#include <bx/math.h>

#include "Camera.h"
#include "Engine.h"
#include "Graphics/Renderer.h"
#include "imgui_impl_bgfx.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "Graphics/Shaders.h"
#include "Objects/Primitives/Cube.h"
#include "UI/Stats.h"

struct PosColorVertex
{
    float x;
    float y;
    float z;
    uint32_t abgr;
};

static PosColorVertex cubeVertices[] =
{
    {-1.0f,  1.0f,  1.0f, 0xff000000 },
    { 1.0f,  1.0f,  1.0f, 0xff0000ff },
    {-1.0f, -1.0f,  1.0f, 0xff00ff00 },
    { 1.0f, -1.0f,  1.0f, 0xff00ffff },
    {-1.0f,  1.0f, -1.0f, 0xffff0000 },
    { 1.0f,  1.0f, -1.0f, 0xffff00ff },
    {-1.0f, -1.0f, -1.0f, 0xffffff00 },
    { 1.0f, -1.0f, -1.0f, 0xffffffff },
};

static const uint16_t cubeTriList[] =
{
    0, 1, 2,
    1, 3, 2,
    4, 6, 5,
    5, 6, 7,
    0, 2, 4,
    4, 2, 6,
    1, 5, 3,
    5, 7, 3,
    0, 4, 1,
    4, 5, 1,
    2, 3, 6,
    6, 3, 7,
};

Camera m_Camera;
Cube* m_Cube;

int main(int argc, char* argv[]) {
    Engine::Start();
    Renderer::InitializeRenderer(1280, 720, "Game Engine");

    UI_Widget* stats = new Stats();
    Engine::AddUIWidget(stats);
    
    unsigned int counter = 0;
    while(!glfwWindowShouldClose(Renderer::GetGLFWWindow()))
    {

        Engine::Update();
        counter++;
    }
    return 0;
}