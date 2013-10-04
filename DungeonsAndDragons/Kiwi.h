#pragma once
class Kiwi
{
public:
    float moveSpeed;
    int right;
    int down;

    Kiwi(void);
    Kiwi(int,int,float);
    ~Kiwi(void);

    void Draw(float);
    void Update(float);
private:
    float x;
    float y;
};