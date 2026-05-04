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
    const int N = 100;
    
    for (int dimensione = 1; dimensione <= 100; dimensione++) {
        
        std::vector<std::vector<int>> vecs(N);
        for (int k = 0; k < N; k++)
        {
            vecs[k].resize(dimensione);
            rf.fill(vecs[k], -1000, 1000);
        }
        
        // Bubble Sort
        std::vector<std::vector<int>> copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) bubble_sort(copies[k]);
        double t_bubble = tc.toc() / N;

        // Insertion Sort
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) insertion_sort(copies[k]);
        double t_insertion = tc.toc() / N;

        // Selection Sort
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) selection_sort(copies[k]);
        double t_selection = tc.toc() / N;

        // Merge Sort
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) merge_sort(copies[k], 0, copies[k].size()-1);
        double t_merge = tc.toc() / N;

        // Quicksort
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) quicksort(copies[k], 0, copies[k].size()-1);
        double t_quick = tc.toc() / N;

        // Quicksort modificato
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) quicksort_modificato(copies[k], 0, copies[k].size()-1, 25);
        double t_quickmodificato = tc.toc() / N;

        // std::sort() 
        copies = vecs;
        tc.tic();
        for (int k = 0; k < N; k++) std::sort(copies[k].begin(), copies[k].end());
        double t_std = tc.toc() / N;

        std::cout << "Dim: " << dimensione << " Bubble: " << t_bubble << " Insertion: " << t_insertion << " Selection: " << t_selection << " Merge: " << t_merge << " Quick: " << t_quick << " Quick_modificato: " << t_quickmodificato << " Std::sort(): " << t_std << std::endl;
    }

    return 0;
}
