#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera
{
public:
    virtual ~Camera() {}

    virtual void SetViewport(float aspectRatio) = 0;
    virtual glm::mat4 ViewMatrix() const = 0;
    virtual glm::mat4 ProjectionMatrix() const = 0;
    virtual glm::vec3 Position() const = 0;
};

#endif
