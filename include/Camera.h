#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>

class Camera{
    public:
        Camera() = default;

        // Camera attributes
        glm::vec3 Position{1.0f};
        float Fov = 45.0f;
        glm::vec2 Sensitivity{0.1f};

        // Returns view matrix
        glm::mat4 getView();

        // Returns perspective matrix
        glm::mat4 getPerspective();

        void update(float xOffset, float yOffset);
    private:
        glm::vec3 m_Front{1.0f, 0.0f, 0.0f}; // Look direction
        float m_Pitch = 45.0f;
        float m_Yaw = 0.0f;
};