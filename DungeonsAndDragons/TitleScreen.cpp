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
    //Textures::ApplySurface(Textures::GetTexture("orange"), 50, 50);

    // Testing
    Textures::DrawTexture("orange", 150, 150);
    Textures::DrawTexture("orange", 250, 250, 350, 350);
    Textures::DrawTexture("orange", 400, 375, 200, 200);
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