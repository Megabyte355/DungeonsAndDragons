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

    Uint32 nextGameTick = SDL_GetTicks();
    int loops;
    float interpolation;

    float now = 0;
    float last = 0;
    float gameTime = 0;

    while (g->isRunning)
    {
        loops = 0;
        while (SDL_GetTicks() > nextGameTick && loops < GameConfig::MAX_FRAMESKIP)
        {
            now = SDL_GetTicks();
            if (now > last)
            {
                gameTime = now - last;
                last = now;
            }
            
            g->Update(gameTime);
            
            nextGameTick += GameConfig::SKIP_TICKS;
            loops++;

            while(SDL_PollEvent(&event))
            {
                g->HandleEvents(g, &event);
            }
        }
        
        interpolation = float(SDL_GetTicks() + GameConfig::SKIP_TICKS - nextGameTick) / float(GameConfig::SKIP_TICKS);
        g->Draw(interpolation);
    }

    delete g;
    return 0;
}