#include <string>
#include <iostream>

// Windows support only
#ifndef SDL_H
#define SDL_H
#include "SDL.h"
#endif

#include "Game.h"
using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;

    Game * g = new Game();
    if (g == nullptr)
    {
        cout << "Unable to load game" << endl;
        return 1;
    }

    while (g->isRunning)
    {
        g->Update();
        g->Draw();
        g->HandleEvents();
    }

    return 0;
}