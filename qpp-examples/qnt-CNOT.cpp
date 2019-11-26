#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  ket psi;
  ket result;
  cmat U;
  
  psi = 10_ket;
  std::cout << "psi = \n";
  std::cout << disp(psi) << '\n';
  U = gt.CNOT;

  result = U * psi;
  std::cout << "result = \n";
  std::cout << disp(result) << '\n';

  U = gt.X;
  result = applyCTRL(psi, U, {0}, {1});
  std::cout << "result = \n";
  std::cout << disp(result) << '\n';

}
