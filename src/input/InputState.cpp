#include "input/InputState.h"

InputState::InputState()
    : m_Keys{}
    , m_MouseButtons{}
    , m_CursorX(0.0)
    , m_CursorY(0.0)
    , m_PreviousCursorX(0.0)
    , m_PreviousCursorY(0.0)
    , m_ScrollX(0.0)
    , m_ScrollY(0.0)
{
}

void InputState::ResetFrame()
{
    m_PreviousCursorX = m_CursorX;
    m_PreviousCursorY = m_CursorY;
    m_ScrollX = 0.0;
    m_ScrollY = 0.0;
}

void InputState::SetKey(int key, bool pressed)
{
    if (key >= 0 && key <= GLFW_KEY_LAST)
        m_Keys[static_cast<std::size_t>(key)] = pressed;
}

bool InputState::IsKeyDown(int key) const
{
    if (key < 0 || key > GLFW_KEY_LAST)
        return false;
    return m_Keys[static_cast<std::size_t>(key)];
}

void InputState::SetMouseButton(int button, bool pressed)
{
    if (button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST)
        m_MouseButtons[static_cast<std::size_t>(button)] = pressed;
}

bool InputState::IsMouseButtonDown(int button) const
{
    if (button < 0 || button > GLFW_MOUSE_BUTTON_LAST)
        return false;
    return m_MouseButtons[static_cast<std::size_t>(button)];
}

void InputState::SetCursorPosition(double x, double y)
{
    m_CursorX = x;
    m_CursorY = y;
}

double InputState::CursorX() const
{
    return m_CursorX;
}

double InputState::CursorY() const
{
    return m_CursorY;
}

double InputState::CursorDeltaX() const
{
    return m_CursorX - m_PreviousCursorX;
}

double InputState::CursorDeltaY() const
{
    return m_CursorY - m_PreviousCursorY;
}

void InputState::SetScrollOffset(double xoffset, double yoffset)
{
    m_ScrollX = xoffset;
    m_ScrollY = yoffset;
}

double InputState::ScrollX() const
{
    return m_ScrollX;
}

double InputState::ScrollY() const
{
    return m_ScrollY;
}
