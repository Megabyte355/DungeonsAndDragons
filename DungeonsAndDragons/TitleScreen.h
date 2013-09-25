#pragma once

#include "Screen.h"
#include <iostream>

class TitleScreen : public Screen
{
public:
    TitleScreen(void);
    ~TitleScreen(void) override;

    void Instance();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void HandleEvents(Game * game, SDL_Event * event) override;
};

