#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  ket sigz0 = st.z0;
  ket sigz1 = st.z1;

  cmat sigx = gt.X;
  ket sigx_sigz0 = sigx * sigz0;
  ket sigx_sigz1 = sigx * sigz1;
  std::cout << "Sigma-x |0> : " << sigx_sigz0[0] << " , " << sigx_sigz0[1] << '\n';
  std::cout << "Sigma-x |1> : " << sigx_sigz1[0] << " , " << sigx_sigz1[1] << '\n';
  
  cmat sigy = gt.Y;
  ket sigy_sigz0 = sigy * sigz0;
  ket sigy_sigz1 = sigy * sigz1;
  std::cout << "Sigma-y |0> : " << sigy_sigz0[0] << " , " << sigy_sigz0[1] << '\n';
  std::cout << "Sigma-y |1> : " << sigy_sigz1[0] << " , " << sigy_sigz1[1] << '\n';
  
  cmat sigz = gt.Z;
  ket sigz_sigz0 = sigz * sigz0;
  ket sigz_sigz1 = sigz * sigz1;
  std::cout << "Sigma-z |0> : " << sigz_sigz0[0] << " , " << sigz_sigz0[1] << '\n';
  std::cout << "Sigma-z |1> : " << sigz_sigz1[0] << " , " << sigz_sigz1[1] << '\n';
  
}
