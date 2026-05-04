#include <iostream>
#include <vector>
#include <limits>

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

template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
   int n1 = q - p + 1;
   int n2 = r - q;
   std::vector<T> L(n1);
   std::vector<T> R(n2);
   for (int i = 0; i < n1; i++)
   {
        L[i] = A[p+i];
   }
   for (int j = 0; j < n2; j++)
   {
        R[j] = A[q+j+1];
   }
   int i = 0, j = 0;
   for (int k = p; k <= r; k++)
   {
        if (i < n1 && (j >= n2 || L[i] <= R[j]))
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
   }

}

template<typename T>
void merge_sort(std::vector<T>& A, int p, int r)
{
    if (p < r) 
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

template<typename T>
int partition(std::vector<T>& A, int p, int r) 
{
    T x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] <= x) 
        {
            i++;
            std::swap(A[i], A[j]); 
        }
    }
    std::swap(A[i + 1], A[r]); 
    return i + 1;
}

template<typename T>
void quicksort(std::vector<T>& A, int p, int r) 
{
    if (p < r) 
    {
        int q = partition(A, p, r); 
        quicksort(A, p, q - 1);     
        quicksort(A, q + 1, r);
    }
}

template<typename T>
void quicksort_modificato(std::vector<T>& A, int p, int r, int soglia)
{
    if (p < r)
    {
        if (r - p + 1 <= soglia)
        {
            // Uso Insertion Sort perché è il più veloce tra gli algoritmi quadratici
            for (int j = p + 1; j <= r; j++)
            {
                T key = A[j];
                int i = j - 1;
                while (i >= p && A[i] > key)
                {
                    A[i + 1] = A[i];
                    i--;
                }
                A[i + 1] = key;
            }
        }
        else
        {
            int q = partition(A, p, r);
            quicksort_modificato(A, p, q - 1, soglia);
            quicksort_modificato(A, q + 1, r, soglia);
        }
    }
}