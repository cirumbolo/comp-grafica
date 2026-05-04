#ifndef GAME_TIME_H
#define GAME_TIME_H

class GameTime
{
public:
    static void Update();
    static float DeltaSeconds();
    static float TotalSeconds();

private:
    static double s_LastSeconds;
    static double s_DeltaSeconds;
    static double s_TotalSeconds;
    static bool s_FirstUpdate;
};

#endif
