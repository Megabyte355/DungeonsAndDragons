#ifndef GAME_H
#include "Game.h"
#endif
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

    SDL_Event event;

    while (g->isRunning)
    {
        g->Update();
        g->Draw();
        while(SDL_PollEvent(&event))
        {
            g->HandleEvents(g, &event);
        }
    }

    delete g;
    return 0;
}