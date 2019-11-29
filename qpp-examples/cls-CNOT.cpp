#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;
  std::cout << ">> Classical CNOT. ";
  std::cout << "Bits are labeled from right to left,\n   ";
  std::cout << "i.e. bit zero is the least significant bit (rightmost).\n";
  
  Dynamic_bitset bits{2};                             

  bool bval[2];
  std::cout << "<< Enter the values of the 2 bits (0 or 1, separated by a space): \n";
  std::cin >> bval[0] >> bval[1];
  
  bits.set(0, bval[0]); // control
  bits.set(1, bval[1]); // target

  //bits.set(0, true); // control
  //bits.set(1, true); // target
  
  std::cout << ">> Control bit, [0]: " << bits.get(0) <<  '\n';
  std::cout << ">> Target  bit, [1]: " << bits.get(1) <<  '\n';

  Bit_circuit bc{bits}; // construct a bit circuit out of a bit set
  std::cout << '\n';
  std::cout << ">> Bit circuit (constructed from the above bitset):\n"
	    << bc << '\n';
  std::cout << '\n';

  // bit [0] is the control bit, bit [1] is the target bit
  bc.CNOT(0, 1);
  //bc.CNOT(0, 1).CNOT(0, 1);

  std::cout << ">> Final bit circuit:\n" << bc << '\n';

  std::cout << ">> Control bit, [0]: " << bc.get(0) <<  '\n';
  std::cout << ">> Target  bit, [1]: " << bc.get(1) <<  '\n';
  /*
  cmat U = gt.CNOT;
  std::cout << '\n';
  std::cout << "CNOT matrix:\n";
  std::cout << disp(U) << '\n';

  U *= U;
  std::cout << '\n';
  std::cout << "CNOT*CNOT matrix:\n" << disp(U) << '\n';
  */
}
