#include <iostream>
#include <algorithm> // Per std::min() e std::max()
#include <cmath>  // Per std::sqrt()

int main()
{
    static const int N = 10;
    double arr[N] = {1.5, 2.0, 4.7, 12.1, 0.5, -3.2, 8.8, 15.3, 7.1, 4.2};
    double min_value = arr[0];
    double max_value = arr[0];
    double somma = arr[0];
    for (int i = 1; i < N; i = i + 1)
    {
        min_value = std::min(min_value, arr[i]);
        max_value = std::max(max_value, arr[i]);
        somma = somma + arr[i];
    }
    double media = somma / N;
    double somma_quadrati = 0.0;
    for (int i = 0; i < N; i = i + 1)
    {   
        double scarto = arr[i] - media;
        somma_quadrati = somma_quadrati + scarto * scarto;
    }
    double varianza = somma_quadrati / N;
    double deviazione_standard = std::sqrt(varianza);
    std::cout << "Minimo: " << min_value << "\n";
    std::cout << "Massimo: " << max_value << "\n";
    std::cout << "Media: " << media << "\n";
    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

    return 0;
}
