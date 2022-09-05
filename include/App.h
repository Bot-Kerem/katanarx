#pragma once

#include "Window.h"
#include "Shader.h"
#include "Camera.h"

#include <string>

class App{
    private:
        const std::string WindowName = "Katanarx";
        const int WindowWidth = 800; 
        const int WindowHeight = 600;

        Window GameWindow{WindowName, WindowWidth, WindowHeight};
        Shader shader{"./../Shaders/triangle.vs", "./../Shaders/triangle.fs"};

        Camera camera{};
    public:
        void processMouse(double posx, double posy);
        void build();
        void run();
        static void Init();
};