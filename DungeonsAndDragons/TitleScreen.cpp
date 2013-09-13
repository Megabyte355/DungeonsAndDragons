#include "TitleScreen.h"
#include "Game.h"

TitleScreen::TitleScreen(void) : Screen("TitleScreen")
{    
}


TitleScreen::~TitleScreen(void)
{
}

void TitleScreen::Instance()
{

}

void TitleScreen::Initialize()
{
    // Reset everything
}

void TitleScreen::Update() 
{

}

void TitleScreen::Draw() 
{
    Textures::ApplySurface(Textures::orange, 50, 50);
}

void TitleScreen::HandleEvents(Game * game, SDL_Event * event) 
{
    switch(event->type)
    {
    case SDL_QUIT:
        break;
    case SDL_KEYDOWN:

        std::cout << "Key pressed: " << event->key.keysym.sym << endl;
        if (event->key.keysym.sym == SDLK_ESCAPE)
        {
            game->isRunning = false;
        }

        break;
    default:
        break;
    }
}