#pragma once

#include "Screen.h"
#include <iostream>
#include "Orange.h"
class TitleScreen : public Screen
{
private:
    Orange o;

public:
    TitleScreen(void);
    ~TitleScreen(void);

    void Instance() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void HandleEvents(Game * game, SDL_Event * event) override;
};

