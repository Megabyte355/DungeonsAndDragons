#include "Orange.h"
#include "Textures.h"

// This is a test orange!

Orange::Orange(void)
{
    x = 300;
    y = 300;
}


Orange::~Orange(void)
{
}

void Orange::Move(float x, float y)
{
    this->x += x;
    this->y += y;
}

void Orange::Draw()
{
    Textures::DrawTexture("orange", x, y);
}

void Orange::Update()
{

}