#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  idx n = 3; // qpp::idx = typedef std::size_t (non-negative interger index)

  bool bval[n];
  std::cout << "<< Enter the values of the 3 bits (0 or 1): \n";
  std::cin >> bval[0] >> bval[1] >> bval[2];

  Bit_circuit bc{n};
  bc.set(0, bval[0]);
  bc.set(1, bval[1]);
  bc.set(2, bval[2]);
  
  std::cout << ">> Control bit 1, [0]: " << bc.get(0) <<  '\n';
  std::cout << ">> Control bit 2, [1]: " << bc.get(1) <<  '\n';
  std::cout << ">> Target  bit, [2]: " << bc.get(2) <<  '\n';

  bc.TOF(0, 1, 2);
  
  std::cout << '\n';
  std::cout << ">> Control bit 1, [0]: " << bc.get(0) <<  '\n';
  std::cout << ">> Control bit 2, [1]: " << bc.get(1) <<  '\n';
  std::cout << ">> Target  bit, [2]: " << bc.get(2) <<  '\n';

  cmat U = gt.TOF;
  //std::cout << '\n';
  //std::cout << "C2NOT matrix:\n";
  //std::cout << disp(U) << '\n';
}
