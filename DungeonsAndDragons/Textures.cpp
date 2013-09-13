#include "Textures.h"

SDL_Renderer * Textures::renderer;

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
}

SDL_Texture* Textures::LoadTexture(const std::string &file, SDL_Renderer *ren)
{
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
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

void Textures::ApplySurface(int x, int y, SDL_Texture *tex)
{
    if (renderer != nullptr)
    {
        //First we must create an SDL_Rect for the position of the image, as SDL
	    //won't accept raw coordinates as the image's position
	    SDL_Rect pos;
	    pos.x = x;
	    pos.y = y;
	    //We also need to query the texture to get its width and height to use
	    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	    SDL_RenderCopy(renderer, tex, NULL, &pos);
    }
}