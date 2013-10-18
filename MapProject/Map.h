#pragma once
#include <iostream>
#include <vector>
#include "ITile.h"

class Map
{
public:
    Map(int, int);
    ~Map(void);

private:
    std::string name;
    int columns;
    int rows;

    //std::vector<std::vector<ITile>> matrix[100][100];
};

