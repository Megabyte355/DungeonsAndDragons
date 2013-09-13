#pragma once
#include <string>
#include <SDL.h>

class Game;

using namespace std;

class Screen
{
private:
    string uniqueName;
public:
    Screen(string name);
    ~Screen(void);

    virtual string GetName();
    virtual void Instance() = 0;
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void HandleEvents(Game * game, SDL_Event * event) = 0;

};