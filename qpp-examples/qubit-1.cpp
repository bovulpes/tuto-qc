#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  ket sigz0 = st.z0;
  std::cout << ">> |0>\n";
  std::cout << disp(sigz0) << '\n';
  std::cout << sigz0[0] << " , " << sigz0[1] << '\n';
  
  ket sigz1 = st.z1;
  std::cout << ">> |1>\n";
  std::cout << disp(sigz1) << '\n';
  std::cout << sigz1[0] << " , " << sigz1[1] << '\n';

  ket sigx0 = st.x0;
  std::cout << ">> |x+>\n";
  std::cout << disp(sigx0) << '\n';
  std::cout << sigx0[0] << " , " << sigx0[1] << '\n';
  
  ket sigx1 = st.x1;
  std::cout << ">> |x->\n";
  std::cout << disp(sigx1) << '\n';
  std::cout << sigx1[0] << " , " << sigx1[1] << '\n';

  ket sigy0 = st.y0;
  std::cout << ">> |y+>\n";
  std::cout << disp(sigy0) << '\n';
  std::cout << sigy0[0] << " , " << sigy0[1] << '\n';
  
  ket sigy1 = st.y1;
  std::cout << ">> |y->\n";
  std::cout << disp(sigy1) << '\n';
  std::cout << sigy1[0] << " , " << sigy1[1] << '\n';
  
}
