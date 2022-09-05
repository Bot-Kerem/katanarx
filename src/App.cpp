#include "App.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

void App::Init(){
    Window::Init();
}

void App::build(){
    GameWindow.setUserPointer(this);
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
        shader.setMat4("view", (float*)glm::value_ptr(camera.getView()));
        shader.setMat4("perspective", (float*)glm::value_ptr(camera.getPerspective()));
        // triangle draw call
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // swaps render image
        GameWindow.swapBuffers();
    }
    
}

void App::processMouse(double posx, double posy){
    float xOffset = posx - (WindowWidth / 2);
    float yOffset = (WindowHeight / 2) - posy;

    camera.update(xOffset, yOffset);

    GameWindow.setMousePosition(WindowWidth / 2, WindowHeight / 2);
}