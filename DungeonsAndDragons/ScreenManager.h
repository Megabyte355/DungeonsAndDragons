#pragma once
#include <vector>
#include <string>
#include "Screen.h"


class ScreenManager
{
public:
    ScreenManager(void);
    ~ScreenManager(void);

    void Initialize();
    void PushScreen(Screen * s);
    void RemoveScreen(Screen * s);
    void RemoveScreen(std::string s);

    void UpdateScreen();
    void DrawScreen();
    void HandleScreenEvents();

private:
    std::vector<Screen> screens;
};

