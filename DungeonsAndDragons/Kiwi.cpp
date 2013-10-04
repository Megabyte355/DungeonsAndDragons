#include "Kiwi.h"
#include "Textures.h"

Kiwi::Kiwi(void)
{
    x = 150;
    y = 100;

    right = 1;
    down = 1;

}


Kiwi::~Kiwi(void)
{
}


void Kiwi::Draw(float interpolation)
{
    Textures::DrawTexture("kiwi", x, y, 200, 200);
}

void Kiwi::Update(float gameTime)
{
    // ===========================================
    //                 Experiment
    // ===========================================
    float moveSpeed = 0.30;
    
    if (x > 800)
    {
        right = -1;
    }
    if (x < 0)
    {
        right = 1;
    }

    if (y > 600)
    {
        down = -1;
    }
    if (y < 0)
    {
        down = 1;
    }

    x += moveSpeed * gameTime * right;
    y += moveSpeed * gameTime * down;
    // ===========================================
    
}