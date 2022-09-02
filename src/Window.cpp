#include "Window.h"

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(std::string title, int width, int height){
    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
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