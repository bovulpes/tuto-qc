#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  // |+> y = 1/sqrt(2) (|0> + i |1>)
  // phi = pi/2
  // theta = pi/4

  //std::cout << disp(pi) << '\n';
  
  cmat Rz_1 = gt.RZ(pi);    // Rz(pi/2+phi)
  cmat Rz_2 = gt.RZ(pi/2.); // Rz(2*theta)
  cmat H    = gt.H;         // Hadamard

  cplx cc = - (cos(pi/8.) + sin(pi/8.) * 1_i);
  //std::cout << disp(cc) << '\n';
  //return 0;
  
  ket psi = cc * Rz_1 * H * Rz_2 * H * st.z0;
  /*
  ket psi = st.z0;
  psi = apply(psi, H,    {0});
  psi = apply(psi, Rz_2, {0});
  psi = apply(psi, H,    {0});
  psi = apply(psi, Rz_1, {0});
  */
  //ket psi = st.y1;
  
  //ket psi = H * st.z0;
  //std::cout << disp(psi) << '\n';
  //return 0;
  
  cmat basisX = hevects(gt.X); // Pauli sigma-x
  auto evals_sigx = hevals(gt.X);
  
  cmat basisY = hevects(gt.Y); // Pauli sigma-y
  auto evals_sigy = hevals(gt.Y);
  
  auto meas_X = measure(psi, basisX);
  auto meas_Y = measure(psi, basisY);
  
  std::cout << "Probabilities X: " << disp(std::get<PROB>(meas_X), ", ") << '\n';

  std::cout << "Probabilities Y: " << disp(std::get<PROB>(meas_Y), ", ") << '\n';
  idx res = std::get<RES>(meas_Y);
  std::cout << "Value: " << disp(evals_sigy[res]) << '\n';
  
}
