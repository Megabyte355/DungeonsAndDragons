#pragma once
#include <iostream>
#include "Config.h"

#ifndef SDL_LIBRARY
#define SDL_LIBRARY
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

class Game
{
public:
    SDL_Renderer * renderer;
    SDL_Window * window;
    bool isRunning;

    Game(void);
    ~Game(void);

    void Initialize();
    void Update();
    void Draw();
    void HandleEvents();
};

