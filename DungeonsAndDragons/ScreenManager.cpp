#include "ScreenManager.h"

ScreenManager* ScreenManager::screenManagerInstance = nullptr;

ScreenManager::ScreenManager(void)
{
}

ScreenManager::~ScreenManager(void)
{
    for (vector<Screen*>::iterator it = storedScreens.begin(); it != storedScreens.end(); it++)
    {
        delete *it;
    }
    storedScreens.clear();
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
    storedScreens.push_back(new TitleScreen());

    PushScreen("TitleScreen");
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

void ScreenManager::Update()
{
    // For each screen in active screens, perform Update()
    CopyActiveScreens();

    for (vector<Screen*>::iterator it = screensToProcess.begin(); it != screensToProcess.end(); it++)
    {
        (*it)->Update();
    }

    CleanCopiedScreens();
}

void ScreenManager::Draw()
{
    // For each screen in active screens, perform Draw()

    CopyActiveScreens();

    for (vector<Screen*>::iterator it = screensToProcess.begin(); it != screensToProcess.end(); it++)
    {
        (*it)->Draw();
    }

    CleanCopiedScreens();
}

void ScreenManager::HandleEvents(SDL_Event event)
{
    // For each screen in active screens, perform HandleEvents()
    CopyActiveScreens();

    for (vector<Screen*>::iterator it = screensToProcess.begin(); it != screensToProcess.end(); it++)
    {
        (*it)->HandleEvents(event);
    }

    CleanCopiedScreens();
}

// Copy all screens in activeScreens to screensToProcess vector
void ScreenManager::CopyActiveScreens()
{
    for (vector<Screen*>::iterator it = activeScreens.begin(); it != activeScreens.end(); it++)
    {
        screensToProcess.push_back(*it);
    }
}

void ScreenManager::CleanCopiedScreens()
{
    screensToProcess.clear();
}