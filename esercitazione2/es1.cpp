#include <iostream>

int main()
{
  double ad[4] = {0.0, 1.1, 2.2, 3.3};
  float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  int ai[3] = {0, 1, 2};

  int x = 1;
  float y = 1.1;

  std::cout << "--- Indirizzi degli array ---" << "\n";
  for (int i = 0; i < 4; ++i) 
  {
    std::cout << "Indirizzo di ad[" << i << "]: " << &ad[i] << "\n";
  }
  std::cout << "\n";
  for (int i = 0; i < 8; ++i) 
  {
    std::cout << "Indirizzo di af[" << i << "]: " << &af[i] << "\n";
  }
  std::cout << "\n";
  for (int i = 0; i < 3; ++i) 
  {
    std::cout << "Indirizzo di ai[" << i << "]: " << &ai[i] << "\n";
  }
  std::cout << "\n";

  std::cout << "--- Indirizzi delle variabili scalari ---" << "\n";
  std::cout << "Indirizzo di x: " << &x << "\n";
  std::cout << "Indirizzo di y: " << &y << "\n";

  (&y)[1] = 0;

  std::cout << x << "\n";

  return 0;
}