#pragma once
class Game
{
public:
    Game(void);
    ~Game(void);

    bool isRunning;
    void Update();
    void Draw();
    void HandleEvents();
};

