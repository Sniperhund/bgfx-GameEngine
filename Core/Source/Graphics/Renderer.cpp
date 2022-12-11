#include "Renderer.h"

#include <iostream>
#include "bgfx/bgfx.h"
#include "bx/math.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

GLFWwindow* Renderer::ms_window = NULL;
uint16_t Renderer::ms_width = 0;
uint16_t Renderer::ms_height = 0;

void Renderer::window_size_callback(GLFWwindow* window, int width, int height)
{
    ms_width = width;
    ms_height = height;
    bgfx::reset(width, height);
}

void Renderer::InitializeRenderer(int width, int height, std::string title) {
    if (!glfwInit()) {
        std::cout << "GLFW could not be initialized!" << std::endl;
        exit(1);
    }

    ms_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwSetWindowSizeCallback(ms_window, window_size_callback);
    ms_width = width;
    ms_height = height;
    
    bgfx::PlatformData pd;
    pd.nwh = glfwGetWin32Window(ms_window);

    bgfx::Init bgfxInit;
    bgfxInit.platformData = pd;
    bgfxInit.type = bgfx::RendererType::Count;
    bgfxInit.resolution.width = width;
    bgfxInit.resolution.height = height;
    bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(bgfxInit);
    
    //bgfx::setDebug(BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS | BGFX_DEBUG_PROFILER);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, width, height);
}

void Renderer::RenderFrame()
{
    glfwPollEvents();
    bgfx::frame();
}
