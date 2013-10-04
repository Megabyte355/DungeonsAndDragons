#include "Textures.h"

SDL_Renderer * Textures::renderer;

// Texture test
std::map<std::string, SDL_Texture*> Textures::textureMap;
SDL_Texture * Textures::orange;
SDL_Texture * Textures::kiwi;


Textures::Textures(void)
{
}

Textures::~Textures(void)
{
    // TO DO: Free all textures in textureMap
}

void Textures::SetRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}
void Textures::LoadAllTextures()
{
    // Load all files here
    orange = LoadTexture("Assets\\orange.png");
    kiwi = LoadTexture("Assets\\kiwi.png");
    textureMap["orange"] = orange;
    textureMap["kiwi"] = kiwi;
}

SDL_Texture* Textures::GetTexture(std::string textureName)
{
    return textureMap[textureName];
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

void Textures::DrawTexture(std::string textureName, int x, int y, int w, int h)
{
    SDL_Texture * tex = textureMap[textureName];
    if (renderer != nullptr && tex != nullptr)
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
    else
    {
        Utils::logSDLError(std::cout, std::string("DrawTexture \"").append(textureName).append("\""));
    }
}

//void Textures::ApplySurface(SDL_Texture *tex, int x, int y, int w, int h)
//{
//    if (renderer != nullptr)
//    {
//	    SDL_Rect pos;
//	    pos.x = x;
//	    pos.y = y;
//	    
//        if (w == 0 || h == 0)
//        {
//            SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
//        }
//        else
//        {
//            pos.w = w;
//            pos.h = h;
//        }
//	    SDL_RenderCopy(renderer, tex, NULL, &pos);
//    }
//}