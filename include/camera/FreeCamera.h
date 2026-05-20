#ifndef FREE_CAMERA_H
#define FREE_CAMERA_H

#include "camera/Camera.h"
#include "input/InputState.h"

#include <glm/vec3.hpp>

class FreeCamera : public Camera
{
public:
    FreeCamera();

    void SetViewport(float aspectRatio) override;
    glm::mat4 ViewMatrix() const override;
    glm::mat4 ProjectionMatrix() const override;
    glm::vec3 Position() const override;

    void SetPosition(const glm::vec3& position);
    void SetOrientation(float yawRadians, float pitchRadians);
    void SetFieldOfView(float fieldOfViewRadians);
    void SetNearFar(float nearPlane, float farPlane);
    void SetMoveSpeed(float unitsPerSecond);
    void SetMouseSensitivity(float radiansPerPixel);

    void Update(const InputState& input, float deltaSeconds);

private:
    glm::vec3 m_Position;
    float m_Yaw;
    float m_Pitch;
    float m_FieldOfView;
    float m_NearPlane;
    float m_FarPlane;
    float m_AspectRatio;
    float m_MoveSpeed;
    float m_MouseSensitivity;

    glm::vec3 Forward() const;
    glm::vec3 Right() const;
    glm::vec3 Up() const;
};

#endif
