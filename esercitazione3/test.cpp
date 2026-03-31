#include <iostream>
#include "es3.hpp"

int main() 
{
    /* Test semplificazione */
    rational<int> r(3, 6); 
    std::cout << "3/6 semplificato: " << r << "\n"; 
    rational<int> s(1, -2);
    std::cout << "1/-2 con correzione segno: " << s << "\n";

    /* Test operatori composti */
    rational<int> n(1, 2);
    n += rational<int>(1, 2); 
    std::cout << "1/2 += 1/2: " << n << "\n";
    n *= rational<int>(3, 1);
    std::cout << "1/1 *= 3/1: " << n << "\n";
    n -= rational<int>(1, 1);
    std::cout << "3/1 -= 1/1: " << n << "\n";
    n /= rational<int>(2, 1);
    std::cout << "2/1 /= 2/1: " << n << "\n";

    /* Test operatori */
    rational<int> a(1, 2);
    rational<int> b(1, 4);
    std::cout << "Somma (1/2 + 1/4): " << (a + b) << "\n";
    std::cout << "Differenza (1/2 - 1/4): " << (a - b) << "\n";
    std::cout << "Prodotto (1/2 * 1/4): " << (a * b) << "\n";
    std::cout << "Divisione (1/2 / 1/4): " << (a / b) << "\n";
    
    /* Test casi speciali */
    rational<int> c(5, 0);
    std::cout << "Operazione con +Inf (1/2 + 5/0): " << (a + c) << "\n";
    rational<int> d(0, 0);
    std::cout << "Operazione con NaN (1/2 * 0/0): " << (a * d) << "\n";
    rational<int> e(-5, 0);
    std::cout << "Operazione con -Inf (1/2 + -5/0): " << (a + e) << "\n";
    std::cout << "Moltiplicazione (5/0 * -5/0): " << (c * e) << "\n";
    
    return 0;
}