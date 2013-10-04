#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Utils.h"
#include <iostream>
#include <map>

class Textures
{
public:
    Textures(void);
    ~Textures(void);
    
    static void SetRenderer(SDL_Renderer *renderer);   
    static void LoadAllTextures();

    // Test
    
    static std::map<std::string, SDL_Texture*> textureMap;
    
    static SDL_Texture * orange;
    static SDL_Texture * kiwi;

    static SDL_Texture* GetTexture(std::string textureName);
    static SDL_Texture* RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize);
    
    static void DrawTexture(std::string textureName, int x, int y, int w = 0, int h = 0);
    //static void ApplySurface(SDL_Texture *tex, int x, int y, int w = 0, int h = 0);

private:
    static SDL_Renderer* renderer;
    static SDL_Texture* LoadTexture(const std::string &file);
};

