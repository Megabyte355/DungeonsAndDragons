#include "Orange.h"
#include "Textures.h"

// This is a test orange!

Orange::Orange(void)
{
    x = 300;
    y = 300;

    up = false;
    down = false;
    left = false;
    right = false;

    moveSpeed = 0.20;
}


Orange::~Orange(void)
{
}

void Orange::Move(float gameTime)
{
    if (up)
    {
        y -= moveSpeed * gameTime;
    }
    if (down)
    {
        y += moveSpeed * gameTime;
    }
    if (left)
    {
        x -= moveSpeed * gameTime;
    }
    if (right)
    {
        x += moveSpeed * gameTime;
    }
}

void Orange::MoveUp(bool x)
{
    up = x;
}

void Orange::MoveDown(bool x)
{
    down = x;
}

void Orange::MoveLeft(bool x)
{
    left = x;
}

void Orange::MoveRight(bool x)
{
    right = x;
}

void Orange::Draw(float interpolation)
{
    if (up)
    {
        Textures::DrawTexture("orange", x, y - moveSpeed * interpolation);
    }
    else if (down)
    {
        Textures::DrawTexture("orange", x, y + moveSpeed * interpolation);
    }
    else if (left)
    {
        Textures::DrawTexture("orange", x - moveSpeed * interpolation, y);
    }
    else if (right)
    {
        Textures::DrawTexture("orange", x + moveSpeed * interpolation, y);
    }
    else
    {
        Textures::DrawTexture("orange", x, y);
    }
}

void Orange::Update()
{

}