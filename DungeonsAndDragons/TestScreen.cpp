#include "TestScreen.h"
#include "Game.h"

TestScreen::TestScreen(void) : Screen("TestScreen")
{   
}


TestScreen::~TestScreen(void)
{
}

void TestScreen::Instance()
{

}

void TestScreen::Initialize()
{
    // Reset everything
}

void TestScreen::Update(float gameTime) 
{
    k.Update(gameTime);
    o.Move(gameTime);
    
}

void TestScreen::Draw(float interpolation) 
{
    k.Draw(interpolation);
    o.Draw(interpolation);
}

void TestScreen::HandleEvents(Game * game, SDL_Event * event) 
{
    switch(event->type)
    {
        case SDL_QUIT:
            game->isRunning = false;
            break;
        case SDL_KEYDOWN:

            //std::cout << "Key pressed: " << event->key.keysym.sym << endl;
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                game->isRunning = false;
            }
            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                    o.MoveUp(true);
                    break;
                case SDLK_DOWN:
                    o.MoveDown(true);
                    break;
                case SDLK_LEFT:
                    o.MoveLeft(true);
                    break;
                case SDLK_RIGHT:
                    o.MoveRight(true);
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            //std::cout << "Key released: " << event->key.keysym.sym << endl;

            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                    o.MoveUp(false);
                    break;
                case SDLK_DOWN:
                    o.MoveDown(false);
                    break;
                case SDLK_LEFT:
                    o.MoveLeft(false);
                    break;
                case SDLK_RIGHT:
                    o.MoveRight(false);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}