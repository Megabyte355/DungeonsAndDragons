#pragma once

#include "Screen.h"
#include <iostream>
#include "Orange.h"
#include "Kiwi.h"

class TestScreen : public Screen
{
private:
    Orange o;
    Kiwi k;


public:
    TestScreen(void);
    ~TestScreen(void) override;

    void Instance();
    void Initialize() override;
    void Update(float) override;
    void Draw(float) override;
    void HandleEvents(Game * game, SDL_Event * event) override;
};