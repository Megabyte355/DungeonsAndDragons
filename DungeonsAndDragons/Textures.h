#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Utils.h"
#include <iostream>

class Textures
{
public:
    Textures(void);
    ~Textures(void);
    
    static void SetRenderer(SDL_Renderer *renderer);
    
    static void LoadAllTextures();

    static SDL_Texture* RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize);
    void ApplySurface(int x, int y, SDL_Texture *tex);

private:
    static SDL_Renderer* renderer;
    static SDL_Texture* LoadTexture(const std::string &file, SDL_Renderer *ren);
};

