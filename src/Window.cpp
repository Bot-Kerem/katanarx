#include "Window.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(std::string title, int width, int height){

    // if you want to make fullscreen set monitor parameter to glfwGetPrimaryMonitor()
    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    
    // some important things
    glfwMakeContextCurrent(m_Window);

    // load opengl
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

bool Window::isClosed(){
    return glfwWindowShouldClose(m_Window);
}

void Window::PollEvents(){
    glfwPollEvents();
}

void Window::swapBuffers(){
    glfwSwapBuffers(m_Window);
}

void Window::Init(){
    if(!glfwInit()){
        throw std::runtime_error("GLFW couldn't initialized!");
    }
}