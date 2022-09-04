cmake_minimum_required(VERSION 3.23.3)

find_package(glfw3 REQUIRED)

project(katanarx)

set(PROJECT_SOURCES
        src/main.cpp
        src/App.cpp
        src/Window.cpp
        src/Shader.cpp

        src/glad.c
        )

include_directories(include)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw)