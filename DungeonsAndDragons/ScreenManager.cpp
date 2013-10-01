#include "ScreenManager.h"

ScreenManager* ScreenManager::screenManagerInstance = nullptr;

ScreenManager::ScreenManager(void)
{
}

ScreenManager::~ScreenManager(void)
{
    while (!storedScreens.empty())
    {
        delete storedScreens.back();
        storedScreens.pop_back();
    }
    activeScreens.clear();
    screensToProcess.clear();
}

ScreenManager * ScreenManager::GetInstance()
{
    if (screenManagerInstance == nullptr)
    {
        screenManagerInstance = new ScreenManager();
    }
    return screenManagerInstance;
}

void ScreenManager::Initialize()
{
    storedScreens.push_back(new TestScreen());

    PushScreen("TestScreen");
}

// Move a screen from storedScreen to activeScreens
void ScreenManager::PushScreen(Screen * s)
{
    s->Initialize();
    activeScreens.push_back(s);
}

void ScreenManager::PushScreen(string s)
{
    for (vector<Screen*>::iterator it = storedScreens.begin(); it != storedScreens.end(); it++)
    {
        if ((*it)->GetName() == s)
        {
            activeScreens.push_back(*it);
            break;
        }
    }
}

// Remove a screen from activeScreens and screensToUpdate
void ScreenManager::PopScreen(Screen * s)
{
    PopScreen(s->GetName());
}

void ScreenManager::PopScreen(std::string s)
{
    for (vector<Screen*>::iterator it = activeScreens.begin(); it != activeScreens.end(); it++)
    {
        if ((*it)->GetName() == s)
        {
            activeScreens.erase(it);
            break;
        }
    }
}

void ScreenManager::Update(float gameTime)
{
    // For each screen in active screens, perform Update()
    CopyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->Update(gameTime);
    }
    CleanCopiedScreens();
}

void ScreenManager::Draw(float interpolation)
{
    // For each screen in active screens, perform Draw()
    CopyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->Draw(interpolation);
    }
    CleanCopiedScreens();
}

void ScreenManager::HandleEvents(Game * game, SDL_Event * event)
{
    // For each screen in active screens, perform HandleEvents()
    CopyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->HandleEvents(game, event);
    }
    CleanCopiedScreens();
}

// Copy all screens in activeScreens to screensToProcess vector
void ScreenManager::CopyActiveScreens()
{
    for (auto s : activeScreens)
    {
        screensToProcess.push_back(s);
    }
}

void ScreenManager::CleanCopiedScreens()
{
    screensToProcess.clear();
}