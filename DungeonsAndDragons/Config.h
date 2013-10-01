#pragma once
namespace GameConfig
{
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    // Game loop settings
    const int TICKS_PER_SECOND = 25;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

}