#pragma once

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Config.h"
#include "Utils.h"
#include "ScreenManager.h"
#include "Textures.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


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
    void HandleEvents(Game * game, SDL_Event * event);
};

#endif