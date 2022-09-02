#include "App.h"

void App::Init(){
    Window::Init();
}

void App::build(){

}

void App::run(){
    build();
    while (!GameWindow.isClosed())
    {
        Window::PollEvents();
        
        GameWindow.swapBuffers();
    }
    
}