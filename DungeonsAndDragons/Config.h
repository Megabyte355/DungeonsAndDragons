#pragma once
namespace GameConfig
{
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;

    // Game loop settings
    const int TICKS_PER_SECOND = 60;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

}