#include <iostream>
#include <vector>
#include <algorithm>
#include "randfiller.h"
#include "sorts.hpp"
#include "timecounter.h"

int main()
{
    randfiller rf;
    timecounter tc;

    std::cout << "Dim\tBubble\tInsert\tSelect\tStd::sort" << std::endl;
    
    for (int dimensione = 4; dimensione <= 8192; dimensione *= 2) {
        
        std::vector<int> vec;
        vec.resize(dimensione);
        rf.fill(vec, -1000, 1000);

        // Creo una copia per ogni metodo di ordinamento che voglio cronometrare
        std::vector<int> v1 = vec;
        std::vector<int> v2 = vec;
        std::vector<int> v3 = vec;
        std::vector<int> v4 = vec;

        // Cronometro il Bubble Sort
        tc.tic();
        bubble_sort(v1);
        double t_bubble = tc.toc();

        // Cronometro l'Insertion Sort
        tc.tic();
        insertion_sort(v2);
        double t_insertion = tc.toc();

        // Cronometro il Selection Sort
        tc.tic();
        selection_sort(v3);
        double t_selection = tc.toc();

        // Cronometro std::sort() 
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double t_std = tc.toc();

        std::cout << "Dim: " << dimensione << " Bubble: " << t_bubble << " Insertion: " << t_insertion << " Selection: " << t_selection << " Std::sort(): " << t_std << std::endl;
    }

    return 0;
}
