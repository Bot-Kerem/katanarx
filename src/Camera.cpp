#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include <cmath>
#include <iostream>

void Camera::update(float xOffset, float yOffset){
    m_Yaw += xOffset * Sensitivity.x;
    m_Pitch += yOffset * Sensitivity.y;

    if (m_Pitch > 89.0f)
            m_Pitch = 89.0f;
    if (m_Pitch < -89.0f)
            m_Pitch = -89.0f;

    // calculating look direction
    glm::vec3 Front;    
    Front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    Front.y = sin(glm::radians(m_Pitch));
    Front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

    // scales between 1 and 0
    m_Front = glm::normalize(Front);
}

glm::mat4 Camera::getView(){
    return glm::lookAt(Position, Position + m_Front, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::getPerspective(){
    return glm::perspective(Fov, 800.0f/600.0f, 0.1f, 100.0f);
}