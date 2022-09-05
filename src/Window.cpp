#include "Window.h"
#include "App.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <stdexcept>

Window::Window(std::string title, int width, int height){

    // if you want to make fullscreen set monitor parameter to glfwGetPrimaryMonitor()
    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwSetCursorPosCallback(m_Window, cursorPositionCallback);

    // sets cursor invisible
    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    
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

void Window::setUserPointer(void* pointer){
    glfwSetWindowUserPointer(m_Window, pointer);
}

 void Window::cursorPositionCallback(GLFWwindow* window, double posx, double posy){
    App* app = (App*)glfwGetWindowUserPointer(window);

    app->processMouse(posx, posy);
 }

 void Window::setMousePosition(double xpos, double ypos){
    glfwSetCursorPos(m_Window, xpos, ypos);
 }