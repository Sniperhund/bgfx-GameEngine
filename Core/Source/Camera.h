#pragma once

#include <glm/ext.hpp>
#include <glm/glm.hpp>

class Camera
{
public:
    glm::vec3 m_position = glm::vec3(1);
    glm::vec3 m_target = glm::vec3(0);
    glm::vec3 m_up = glm::vec3(0, 0, 1);

    float m_fov = 60;
    float m_near_clip = 0.1f;
    float m_far_clip = 100.0f;

    glm::mat4 getViewMatrix() const { return glm::lookAt(m_position, m_target, m_up); }
};
