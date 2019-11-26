#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;
  
  ket psiz0 = st.z0;
  std::cout << "plus-z:\n" << disp(psiz0) << '\n';
  std::cout << '\n';

  //
  cmat basisX = hevects(gt.X); // Pauli sigma-x

  std::cout << "gt.X matrix:\n" << disp(gt.X) << '\n';
  std::cout << '\n';
  std::cout << "gt.X matrix of eigen-vectors:\n" << disp(basisX) << '\n';
  std::cout << '\n';
  /*
  std::cout << disp(basisX(0,0)) << '\n';
  std::cout << disp(basisX(0,1)) << '\n';
  std::cout << disp(basisX(1,0)) << '\n';
  std::cout << disp(basisX(1,1)) << '\n';
  */
  auto measured = measure(psiz0, basisX);

  std::cout << "Probabilities: " << disp(std::get<PROB>(measured), ", ") << '\n';
  std::cout << '\n';

  std::cout << "Result: " << std::get<RES>(measured) << '\n';
  std::cout << '\n';
  
  //
  cmat basisY = hevects(gt.Y); // Pauli sigma-y

  std::cout << "gt.Y matrix:\n" << disp(gt.Y) << '\n';
  std::cout << '\n';
  std::cout << "gt.Y matrix of eigen-vectors:\n" << disp(basisY) << '\n';
  std::cout << '\n';

  //
  cmat basisZ = hevects(gt.Z); // Pauli sigma-z

  std::cout << "gt.Z matrix:\n" << disp(gt.Z) << '\n';
  std::cout << '\n';
  std::cout << "gt.Z matrix of eigen-vectors:\n" << disp(basisZ) << '\n';
  std::cout << '\n';

  //
  auto evals_sigz = hevals(gt.Z);

  ket psiz = sqrt(1./3.) * st.z0 + sqrt(2./3.) * st.z1;
  std::cout << "psiz = sqrt(1/3)|0> + sqrt(2/3)|1>\n" << disp(psiz) << '\n';
  std::cout << '\n';

  idx N = 10;
  idx Nmeas0 = 0, Nmeas1 = 0;
  for(idx i = 0; i < N; ++i) {

    std::cout << "========== Measurement " << disp(i) << " ==========\n";
    
    auto meas_sigz = measure(psiz, basisZ);
    
    idx res = std::get<RES>(meas_sigz);
    ket state = std::get<ST>(meas_sigz)[res];

    //std::cout << "Probabilities: " << disp(std::get<PROB>(meas_sigz), ", ") << '\n';
    //std::cout << '\n';    
    std::cout << "Result: " << res << '\n';
    std::cout << "Value: " << disp(evals_sigz[res]) << '\n';
    std::cout << "State: \n" << disp(state) << '\n';

    //ket state_sigz = gt.Z * state;
    //std::cout << "gtZ * state" << disp(state_sigz) << '\n';
    //std::cout << '\n';
    
    if (evals_sigz[res] == +1) ++Nmeas0;
    if (evals_sigz[res] == -1) ++Nmeas1;
    
  }

  float Pmeas0 = (float)(Nmeas0)/(float)(Nmeas0 + Nmeas1);
  float Pmeas1 = (float)(Nmeas1)/(float)(Nmeas0 + Nmeas1);
  std::cout << "Pmeas0 (+1) = " << Pmeas0 << " , Pmeas1 (-1) = " << Pmeas1 << '\n';

  ket psiz_sigz = gt.Z * psiz;
  std::cout << "gtZ * psiz \n" << disp(psiz_sigz) << '\n';
  std::cout << '\n';
 
}
