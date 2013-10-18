#pragma once

#include "ITileOccupant.h"

class ITile
{
public:
    ITile(void);
    ~ITile(void);

    virtual bool IsOccupied() = 0;
    virtual ITileOccupant GetOccupant() = 0;
private:
    ITileOccupant occupier;
};