#pragma once
class Orange
{
public:
    bool up;
    bool down;
    bool left;
    bool right;

    float moveSpeed;

    Orange(void);
    ~Orange(void);

    void Draw(float);
    void Update();
    void Move(float);

    void MoveUp(bool);
    void MoveDown(bool);
    void MoveLeft(bool);
    void MoveRight(bool);

private:
    float x;
    float y;
};

