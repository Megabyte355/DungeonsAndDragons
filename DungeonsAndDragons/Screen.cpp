#include "Screen.h"


Screen::Screen(string name)
{
    uniqueName = name;
}


Screen::~Screen(void)
{
}

string Screen::GetName()
{
    return uniqueName;
}