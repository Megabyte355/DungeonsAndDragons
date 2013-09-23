#pragma once

#include "Screen.h"
#include <iostream>

class TitleScreen : public Screen
{
public:
    TitleScreen(void);
    ~TitleScreen(void);

    void Instance() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void HandleEvents(Game * game, SDL_Event * event) override;
};

