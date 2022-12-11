#pragma once
#define BX_CONFIG_DEBUG 1
#include <string>
#include <GLFW/glfw3.h>

class Renderer
{
    static GLFWwindow* ms_window;
    static uint16_t ms_width;
    static uint16_t ms_height;
    
    static void window_size_callback(GLFWwindow* window, int width, int height);
public:
    static void InitializeRenderer(int width, int height, std::string title);
    static void RenderFrame();

    static GLFWwindow* GetGLFWWindow() { return ms_window; }
};