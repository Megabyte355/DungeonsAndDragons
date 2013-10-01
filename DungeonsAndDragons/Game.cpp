#include "Game.h"

Game::Game(void)
{

    screenManager = nullptr;
    renderer = nullptr;
    window = nullptr;
    
    Initialize();
}


Game::~Game(void)
{
    isRunning = false;
    delete screenManager;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

	SDL_Quit();

    std::cout << "Game Destroyed" << std::endl;   
}

void Game::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
		Utils::logSDLError(std::cout, "SDL_Init");
		return;
	}
	if (TTF_Init() == -1)
    {
		std::cout << TTF_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow("Lesson 6", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		Utils::logSDLError(std::cout, "SDL_CreateWindow");
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
        Utils::logSDLError(std::cout, "SDL_CreateRenderer");
		return;
	}
    
    Textures::SetRenderer(renderer);
    Textures::LoadAllTextures();
    screenManager = ScreenManager::GetInstance();
    screenManager->Initialize();

    
    //SDL_Delay(5000);
    isRunning = true;

    std::cout << "Game Started" << std::endl;
}

void Game::Update(float gameTime)
{
    screenManager->Update(gameTime);
}

void Game::Draw(float interpolation)
{
    SDL_RenderClear(renderer);
    screenManager->Draw(interpolation);
    SDL_RenderPresent(renderer);
}

void Game::HandleEvents(Game * game, SDL_Event * event)
{
    screenManager->HandleEvents(game, event);
}
