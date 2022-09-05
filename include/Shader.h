#pragma once

#include <string>

class Shader{
    private:
        unsigned int m_Program{0};

        std::string openFile(std::string path);
    public:
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
        ~Shader();

        void setMat4(const char* varName, float* value);
        
        void use();
};