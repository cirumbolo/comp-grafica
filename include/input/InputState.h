#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include <array>

#include <GLFW/glfw3.h>

class InputState
{
public:
    InputState();

    void ResetFrame();

    void SetKey(int key, bool pressed);
    bool IsKeyDown(int key) const;

    void SetMouseButton(int button, bool pressed);
    bool IsMouseButtonDown(int button) const;

    void SetCursorPosition(double x, double y);
    double CursorX() const;
    double CursorY() const;
    double CursorDeltaX() const;
    double CursorDeltaY() const;

    void SetScrollOffset(double xoffset, double yoffset);
    double ScrollX() const;
    double ScrollY() const;

private:
    std::array<bool, GLFW_KEY_LAST + 1> m_Keys;
    std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> m_MouseButtons;
    double m_CursorX;
    double m_CursorY;
    double m_PreviousCursorX;
    double m_PreviousCursorY;
    double m_ScrollX;
    double m_ScrollY;
};

#endif
