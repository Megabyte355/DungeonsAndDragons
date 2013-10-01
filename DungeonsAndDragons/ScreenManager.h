#pragma once
#include <vector>
#include <string>
#include "Screen.h"

#include "TitleScreen.h"
#include "TestScreen.h"
#include <SDL.h>

class Game;

class ScreenManager
{
public:
    static ScreenManager * GetInstance();
    ~ScreenManager(void);

    void Initialize();
    void PushScreen(Screen * s);
    void PushScreen(std::string s);
    void PopScreen(Screen * s);
    void PopScreen(std::string s);

    void Update();
    void Draw();
    void HandleEvents(Game * game, SDL_Event * event);

private:
    ScreenManager(void);
    
    static ScreenManager* screenManagerInstance;
    std::vector<Screen*> storedScreens;
    std::vector<Screen*> activeScreens;
    std::vector<Screen*> screensToProcess;
    
    void CopyActiveScreens();
    void CleanCopiedScreens();
};

