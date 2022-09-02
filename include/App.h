#pragma once

#include "Window.h"

#include <string>

class App{
    private:
        const std::string WindowName = "Katanarx";
        const int WindowWidth = 800; 
        const int WindowHeight = 600;

        Window GameWindow{WindowName, WindowWidth, WindowHeight};
    public:
        void build();
        void run();
        static void Init();
};