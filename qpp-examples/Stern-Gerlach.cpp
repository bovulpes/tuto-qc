#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  ket psi = randket(2);
  std::cout << "Initial psi:\n" << disp(psi) << '\n';

  // sigma-z measurement
  cmat basisZ = hevects(gt.Z);
  auto evals_sigz = hevals(gt.Z);
  
  auto meas_z_1 = measure(psi, basisZ);

  std::cout << "Probabilities (Z_1): " << disp(std::get<PROB>(meas_z_1), ", ") << '\n';
  std::cout << '\n';
  double p_0 = std::get<PROB>(meas_z_1)[0];
  double p_1 = std::get<PROB>(meas_z_1)[1];
  float av_sigz = (-1) * p_0 + (+1) * p_1;  // values are inverted !!!
  std::cout << "Average sigma-z: " << av_sigz << '\n';

  // with projectors
  cmat proj_z0 = st.pz0;
  cmat proj_z1 = st.pz1;
  ket psi_p = proj_z0 * psi;
  p_0 = (adjoint(psi) * psi_p).value().real();
  psi_p = proj_z1 * psi;
  p_1 = (adjoint(psi) * psi_p).value().real();
  av_sigz = (+1) * p_0 + (-1) * p_1;  // values not inverted
  std::cout << "Average sigma-z (projectors): " << av_sigz << '\n';
  
  idx res = std::get<RES>(meas_z_1);
  ket psi_z = std::get<ST>(meas_z_1)[res];
  std::cout << "Value: " << disp(evals_sigz[res]) << '\n';
  std::cout << "State: \n" << disp(psi_z) << '\n';

  // sigma-x measurement
  cmat basisX = hevects(gt.X);
  auto evals_sigx = hevals(gt.X);
  
  auto meas_x = measure(psi_z, basisX);

  std::cout << "\nProbabilities (X): " << disp(std::get<PROB>(meas_x), ", ") << '\n';
  std::cout << '\n';
  p_0 = std::get<PROB>(meas_x)[0];
  p_1 = std::get<PROB>(meas_x)[1];
  float av_sigx = (+1) * p_0 + (-1) * p_1;
  std::cout << "Average sigma-x: " << av_sigx << '\n';
  
  res = std::get<RES>(meas_x);
  ket psi_x = std::get<ST>(meas_x)[res];
  std::cout << "Value: " << disp(evals_sigx[res]) << '\n';
  std::cout << "State: \n" << disp(psi_x) << '\n';

  // and again sigma-z measurement
  auto meas_z_2 = measure(psi_x, basisZ);

  std::cout << "\nProbabilities (Z_2): " << disp(std::get<PROB>(meas_z_2), ", ") << '\n';
  std::cout << '\n';
  p_0 = std::get<PROB>(meas_z_2)[0];
  p_1 = std::get<PROB>(meas_z_2)[1];
  av_sigz = (+1) * p_0 + (-1) * p_1;
  std::cout << "Average sigma-z: " << av_sigz << '\n';

}
