#include "App.h"

#include <glad/glad.h>

void App::Init(){
    Window::Init();
}

void App::build(){
    // sets clear color in rgba format
    glClearColor(0.52f, 0.52f, 0.52f, 1.0f); // gray
}

void App::run(){
    build();
    // main loop
    while (!GameWindow.isClosed())
    {
        Window::PollEvents();

        // clear screen
        glClear(GL_COLOR_BUFFER_BIT);

        // activate shader
        shader.use();
        // triangle draw call
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // swaps render image
        GameWindow.swapBuffers();
    }
    
}