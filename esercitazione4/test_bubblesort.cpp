#include<iostream>
#include<vector>
#include<string>
#include<random>
#include<stdlib.h> // Per EXIT_FAILURE e EXIT_SUCCESS
#include "randfiller.h"
#include "sorts.hpp"

int main()
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> size(0, 1000);
    randfiller rf;
    for (int i = 0; i < 100; i++)
    {
        int dimensione = size(generator);
        std::vector<int> vec;
        vec.resize(dimensione);
        rf.fill(vec, -1000, 1000);
        bubble_sort(vec);
        if (is_sorted(vec) == false) return EXIT_FAILURE;
    }
    
    std::vector<std::string> str = {"programmazione", "calcolo", "scientifico", "esercitazione", "compito", "università", "matteo", "iris", "lavoro", "zaino"};
    bubble_sort(str);
    if (is_sorted(str) == false) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
