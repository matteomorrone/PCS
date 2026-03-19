#include <iostream>

int main() 
{
    static const int N = 10;
    double arr[N] = {1.5, 2.0, 4.7, 12.1, 0.5, -3.2, 8.8, 15.3, 7.1, 4.2};
    int scambi = 1; // Valore fasullo per avviare il ciclo while
    while (scambi != 0) 
    {
        scambi = 0; // Azzero il contatore
        for (int i = 0; i < N - 1; i = i + 1) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                double scambiata = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = scambiata;
                scambi = scambi + 1;
            }
        }
    }
    std::cout << "Array ordinato: ";
    for (int i = 0; i < N; i = i + 1) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}