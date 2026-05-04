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
        if (vec.size() > 0) quicksort(vec, 0, vec.size()-1);
        if (is_sorted(vec) == false) return EXIT_FAILURE;
    }
    
    std::vector<std::string> str = {"programmazione", "calcolo", "scientifico", "esercitazione", "compito", "università", "matteo", "iris", "lavoro", "zaino"};
    quicksort(str, 0, str.size()-1);
    if (is_sorted(str) == false) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}