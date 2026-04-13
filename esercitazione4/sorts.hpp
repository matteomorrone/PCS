#include <iostream>
#include <vector>

/* Verifico se il vettore è ordinato*/
template<typename T>
bool is_sorted(const std::vector<T>& vec) 
{
    // Un vettore di lunghezza zero è ordinato
    if (vec.size() == 0) 
    {
        return true; 
    }

    for (size_t i = 1; i < vec.size(); i++) 
    {
        if (vec[i] < vec[i-1]) 
        {
            return false;
        }
    }
    
    return true; 
}

/* Algoritmi di ordinamento*/
template<typename T>
void bubble_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) return;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = vec.size() - 1; j >= i + 1; j--)
        {
            if (vec[j] < vec[j - 1])
            {
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) return;
    for (size_t j = 1; j < vec.size(); j++)
    {
        T key = vec[j];

        // Trasformo j in int per poter gestire i = -1
        int i = static_cast<int>(j) - 1;
    
        while (i >= 0 && vec[i] > key)
        {
            vec[i + 1] = vec[i];
            i = i - 1;
        }
        vec[i + 1] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) return;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(vec[i], vec[min_index]);
        }
    }
}