#pragma once

#include <string>

struct GLFWwindow;

class Window{
    private:
        GLFWwindow* m_Window;
    public:
        Window(std::string title, int width, int height);

        bool isClosed();

        void swapBuffers();

        static void PollEvents();
        static void Init();
};

