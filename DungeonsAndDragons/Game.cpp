#include "Game.h"

Game::Game(void)
{
    // ---Temporary---
    isRunning = false;
    // ---------------

    renderer = nullptr;
    window = nullptr;

    Initialize();
}


Game::~Game(void)
{
    isRunning = false;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

	SDL_Quit();

    std::cout << "Game Destroyed" << std::endl;   
}

void Game::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
		std::cout << SDL_GetError() << std::endl;
		return;
	}
	if (TTF_Init() == -1)
    {
		std::cout << TTF_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow("Lesson 6", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
		| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return;
	}

    // SDL_Delay(5000);
    std::cout << "Game Started" << std::endl;
}

void Game::Update()
{
}

void Game::Draw()
{
}

void Game::HandleEvents()
{
}
