#pragma once
#include <ostream>
#include <SDL.h>
#include <string>

class Utils
{
public:
    static void logSDLError(std::ostream &os, const std::string &msg);
};