#pragma once
#include <iostream>
#include <string>
#include "Config.h"
#include "Utils.h"
#include "ScreenManager.h"
#include "Textures.h"

#ifndef SDL_LIBRARY
#define SDL_LIBRARY
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

class Game
{
public:
    ScreenManager * screenManager;
    SDL_Renderer * renderer;
    SDL_Window * window;
    bool isRunning;

    Game(void);
    ~Game(void);

    void Initialize();
    void Update();
    void Draw();
    void HandleEvents(SDL_Event event);
};

