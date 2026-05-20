#include "camera/FreeCamera.h"

#include <algorithm>
#include <cmath>

#include <glm/geometric.hpp>

namespace
{
glm::mat4 MakeCameraView(const glm::vec3& position, const glm::vec3& forward, const glm::vec3& up)
{
    glm::vec3 w = -forward;
    glm::vec3 u = glm::normalize(glm::cross(up, w));
    glm::vec3 v = glm::cross(w, u);

    return glm::mat4(
        u.x, v.x, w.x, 0.0f,
        u.y, v.y, w.y, 0.0f,
        u.z, v.z, w.z, 0.0f,
        -glm::dot(u, position), -glm::dot(v, position), -glm::dot(w, position), 1.0f
    );
}

glm::mat4 MakePerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
{
    float top = std::fabs(nearPlane) * std::tan(fieldOfView * 0.5f);
    float right = top * aspectRatio;

    return glm::mat4(
        nearPlane / right, 0.0f, 0.0f, 0.0f,
        0.0f, nearPlane / top, 0.0f, 0.0f,
        0.0f, 0.0f, (nearPlane + farPlane), -farPlane * nearPlane,
        0.0f, 0.0f, 1.0f, 0.0f
    ) * -1.0f;
}
}

FreeCamera::FreeCamera()
    : m_Position(0.0f, 2.5f, 6.0f)
    , m_Yaw(-1.5707963f)
    , m_Pitch(0.0f)
    , m_FieldOfView(1.0471976f)
    , m_NearPlane(0.1f)
    , m_FarPlane(100.0f)
    , m_AspectRatio(4.0f / 3.0f)
    , m_MoveSpeed(8.0f)
    , m_MouseSensitivity(0.0025f)
{
}

void FreeCamera::SetViewport(float aspectRatio)
{
    m_AspectRatio = aspectRatio;
}

glm::mat4 FreeCamera::ViewMatrix() const
{
    glm::vec3 forward = Forward();
    glm::vec3 up = Up();

    return MakeCameraView(m_Position, forward, up);
}

glm::mat4 FreeCamera::ProjectionMatrix() const
{
    return MakePerspective(m_FieldOfView, m_AspectRatio, m_NearPlane, m_FarPlane);
}

glm::vec3 FreeCamera::Position() const
{
    return m_Position;
}

void FreeCamera::SetPosition(const glm::vec3& position)
{
    m_Position = position;
}

void FreeCamera::SetOrientation(float yawRadians, float pitchRadians)
{
    m_Yaw = yawRadians;
    m_Pitch = pitchRadians;
}

void FreeCamera::SetFieldOfView(float fieldOfViewRadians)
{
    m_FieldOfView = fieldOfViewRadians;
}

void FreeCamera::SetNearFar(float nearPlane, float farPlane)
{
    m_NearPlane = nearPlane;
    m_FarPlane = farPlane;
}

void FreeCamera::SetMoveSpeed(float unitsPerSecond)
{
    m_MoveSpeed = unitsPerSecond;
}

void FreeCamera::SetMouseSensitivity(float radiansPerPixel)
{
    m_MouseSensitivity = radiansPerPixel;
}

void FreeCamera::Update(const InputState& input, float deltaSeconds)
{
    glm::vec3 forward = Forward();
    glm::vec3 right = Right();
    glm::vec3 up = Up();

    if (input.IsKeyDown(GLFW_KEY_W))
        m_Position += forward * (m_MoveSpeed * deltaSeconds);
    if (input.IsKeyDown(GLFW_KEY_S))
        m_Position -= forward * (m_MoveSpeed * deltaSeconds);
    if (input.IsKeyDown(GLFW_KEY_D))
        m_Position += right * (m_MoveSpeed * deltaSeconds);
    if (input.IsKeyDown(GLFW_KEY_A))
        m_Position -= right * (m_MoveSpeed * deltaSeconds);
    if (input.IsKeyDown(GLFW_KEY_E))
        m_Position += up * (m_MoveSpeed * deltaSeconds);
    if (input.IsKeyDown(GLFW_KEY_Q))
        m_Position -= up * (m_MoveSpeed * deltaSeconds);

    if (input.IsMouseButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
    {
        m_Yaw += static_cast<float>(-input.CursorDeltaX()) * m_MouseSensitivity;
        m_Pitch += static_cast<float>(-input.CursorDeltaY()) * m_MouseSensitivity;

        const float pitchLimit = 1.553343f;
        m_Pitch = std::max(-pitchLimit, std::min(pitchLimit, m_Pitch));
    }
}

glm::vec3 FreeCamera::Forward() const
{
    float cosPitch = std::cos(m_Pitch);
    return glm::normalize(glm::vec3(
        cosPitch * std::cos(m_Yaw),
        std::sin(m_Pitch),
        cosPitch * std::sin(m_Yaw)
    ));
}

glm::vec3 FreeCamera::Right() const
{
    return glm::normalize(glm::cross(Forward(), glm::vec3(0.0f, 1.0f, 0.0f)) * -1.0f);
}

glm::vec3 FreeCamera::Up() const
{
    return glm::normalize(glm::cross(Right(), Forward()));
}
