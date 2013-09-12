#pragma once
class Screen
{
public:
    Screen(void);
    ~Screen(void);

    virtual void Instance() = 0;
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void HandleEvents() = 0;
};

