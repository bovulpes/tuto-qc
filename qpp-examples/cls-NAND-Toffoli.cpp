#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  Bit_circuit bc{3};
  bc.set(2, true);

  std::cout << "a   b  | a NAND b\n";
  std::cout << "-----------------\n";
  bc.set(0, false);
  bc.set(1, false);
  std::cout << bc.get(0) << "   " << bc.get(1) << "  |     ";
  bc.TOF(0, 1, 2);
  std::cout << bc.get(2) << '\n';
  
  bc.set(0, false);
  bc.set(1, true);
  std::cout << bc.get(0) << "   " << bc.get(1) << "  |     ";
  bc.TOF(0, 1, 2);
  std::cout << bc.get(2) << '\n';
  
  bc.set(0, true);
  bc.set(1, false);
  std::cout << bc.get(0) << "   " << bc.get(1) << "  |     ";
  bc.TOF(0, 1, 2);
  std::cout << bc.get(2) << '\n';
  
  bc.set(0, true);
  bc.set(1, true);
  std::cout << bc.get(0) << "   " << bc.get(1) << "  |     ";
  bc.TOF(0, 1, 2);
  std::cout << bc.get(2) << '\n';

}
