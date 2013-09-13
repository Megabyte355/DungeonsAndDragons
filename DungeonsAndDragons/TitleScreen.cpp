#include "TitleScreen.h"

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

}

void TitleScreen::HandleEvents(SDL_Event event) 
{
    switch(event.type)
    {
    case SDL_QUIT:
        break;
    case SDL_KEYDOWN:

        std::cout << "Key pressed: " << event.key.keysym.sym << endl;
        //switch(event.key.keysym.sym)
        //{
        //case SDLK_a:
        //    std::cout << "a key pressed" << endl;
        //}
    }
}