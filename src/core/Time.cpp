#include "core/Time.h"

#include <GLFW/glfw3.h>

double GameTime::s_LastSeconds = 0.0;
double GameTime::s_DeltaSeconds = 0.0;
double GameTime::s_TotalSeconds = 0.0;
bool GameTime::s_FirstUpdate = true;

void GameTime::Update()
{
    double currentSeconds = glfwGetTime();

    if (s_FirstUpdate)
    {
        s_LastSeconds = currentSeconds;
        s_DeltaSeconds = 0.0;
        s_TotalSeconds = 0.0;
        s_FirstUpdate = false;
        return;
    }

    s_DeltaSeconds = currentSeconds - s_LastSeconds;
    s_TotalSeconds += s_DeltaSeconds;
    s_LastSeconds = currentSeconds;
}

float GameTime::DeltaSeconds()
{
    return static_cast<float>(s_DeltaSeconds);
}

float GameTime::TotalSeconds()
{
    return static_cast<float>(s_TotalSeconds);
}
