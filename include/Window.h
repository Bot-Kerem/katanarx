#pragma once

#include <string>

struct GLFWwindow;

class Window{
    private:
        GLFWwindow* m_Window;

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
};

