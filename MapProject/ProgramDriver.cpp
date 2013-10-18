#include <iostream>
#include "Map.h"
int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;

    // Test
    std::vector<std::vector<ITile*>> * matrix = new std::vector<std::vector<ITile*>>();

    
    
    std::cout << matrix->size() << std::endl;
    std::cout << matrix[0].size() << std::endl;

    matrix->resize(10);
    /*for (auto v : *matrix)
    {
        v.resize(200);
    }*/
    
    for (int i = 0; i < matrix->size(); i++)
    {
        (*matrix)[i].resize(15);
    }
    std::cout << matrix->size() << std::endl;
    std::cout << (*matrix)[0].size() << std::endl;
    //std::cout << matrix->[0].size() << std::endl;

    int a = 0;
    std::cin >> a;
    return 0;
}