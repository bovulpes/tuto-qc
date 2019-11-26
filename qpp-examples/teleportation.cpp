#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  // input state
  ket psi_a = randket(2);

  psi_a[0] = -0.545076 + 0.796215 * 1_i;
  psi_a[1] = -0.093428 + 0.245366 * 1_i;
  
  std::cout << "Initial state: \n";
  std::cout << disp(psi_a) << '\n';

  // the entangled resource
  ket phi_AB = st.b00;
  std::cout << "The Bell 00 state: \n";
  std::cout << disp(phi_AB) << '\n';

  // the global input state
  ket input_aAB = kron(psi_a, phi_AB);
  std::cout << "The global input state: \n";
  std::cout << disp(input_aAB) << '\n';

  // apply a CNOT on qubits 'AB' followed by an H on qubit 'a'
  input_aAB = applyCTRL(input_aAB, gt.X, {0}, {1});
  input_aAB = apply(input_aAB, gt.H, {0});

  // measure the aA part
  auto results = measure_seq(input_aAB, {0, 1});

  // measurement results
  idx z = std::get<RES>(results)[0];
  idx x = std::get<RES>(results)[1];

  std::cout << ">> Alice's measurement results: ";
  std::cout << "x= " << x << " and z= " << z;

  // probability of obtaining the measurement results x and z
  double p = std::get<PROB>(results);
  std::cout << ", obtained with probability: " << p << '\n';
  
}
