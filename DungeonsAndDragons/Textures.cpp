#include "Textures.h"

SDL_Renderer * Textures::renderer;

// Texture test
SDL_Texture * Textures::orange;

Textures::Textures(void)
{
}

Textures::~Textures(void)
{
}

void Textures::SetRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}
void Textures::LoadAllTextures()
{
    // Load all files here
    orange = LoadTexture("Assets\\orange.png");
}

SDL_Texture* Textures::LoadTexture(const std::string &file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr)		
		Utils::logSDLError(std::cout, "LoadTexture");
	return texture;
}

SDL_Texture* Textures::RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize)
{
    if (renderer != nullptr)
    {
        //Open the font
	    TTF_Font *font = nullptr;
	    font = TTF_OpenFont(fontFile.c_str(), fontSize);
	    if (font == nullptr)
		    throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
	
	    //Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
	    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	    //Clean up unneeded stuff
	    SDL_FreeSurface(surf);
	    TTF_CloseFont(font);

	    return texture;
    }
	return nullptr;
}

void Textures::ApplySurface(SDL_Texture *tex, int x, int y, int w, int h)
{
    if (renderer != nullptr)
    {
	    SDL_Rect pos;
	    pos.x = x;
	    pos.y = y;
	    
        if (w == 0 || h == 0)
        {
            SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
        }
        else
        {
            pos.w = w;
            pos.h = h;
        }
	    SDL_RenderCopy(renderer, tex, NULL, &pos);
    }
}