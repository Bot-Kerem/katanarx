#pragma once

#include <string>

struct GLFWwindow;

class Window{
    private:
        GLFWwindow* m_Window;

        static void cursorPositionCallback(GLFWwindow* window, double posx, double posy);
    public:
        Window(std::string title, int width, int height);
        
        // returns true if window closed
        bool isClosed();

        // swaps opengl render data
        void swapBuffers();

        // processes events
        static void PollEvents();

        // initialize glfw
        static void Init();

        void setMousePosition(double xpos, double ypos);

        void setUserPointer(void* pointer);
};

