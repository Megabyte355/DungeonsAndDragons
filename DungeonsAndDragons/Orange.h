#pragma once
class Orange
{
public:
    Orange(void);
    ~Orange(void);

    void Draw();
    void Update();
    void Move(float x, float y);

private:
    float x;
    float y;
};

