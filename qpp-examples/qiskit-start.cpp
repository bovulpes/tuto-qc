#include <iostream>

#include "qpp.h"

int main() {
  using namespace qpp;

  // quantum circuit with 3 qubits and 2 classical bits
  QCircuit qc{3, 3};

  // add a H gate on qubit 0, putting this qubit in superposition
  qc.gate(gt.H, 0);

  // add a CNOT (CX) gate on control qubit 0 and target qubit 1,
  // putting the qubits in a Bell state
  qc.CTRL(gt.X, 0, 1);

  // add a CNOT (CX) gate on control qubit 0 and target qubit 2,
  // putting the qubits in a GHZ state
  // (Greenberger-Horne-Zeilinger)
  qc.CTRL(gt.X, 0, 2);

  // measurement of a single qubit in the computational basis
  // (target qubit, classical register to store the value)
  qc.measureZ(0, 0);
  qc.measureZ(1, 1);
  qc.measureZ(2, 2);

  // initialize the quantum engine with the circuit
  QEngine engine(qc);

  // display the quantum circuit
  std::cout << ">> BEGIN CIRCUIT\n";
  std::cout << engine.get_circuit() << '\n';
  std::cout << ">> END CIRCUIT\n\n";

  idx shots = 1024;

  // execute the entire circuit step by step, same effect as engine.execute();
  //for (auto&& step : qc) {
  //  engine.execute(step);
  //}
  
  engine.execute(shots);
  auto stats = engine.get_stats();
  
  std::cout << "Stats:\n";
  float prob;
  for (auto stat : stats) {
    prob = stat.second/(float)(shots);
    std::cout << stat.first << " , " << prob << '\n';
  }
  /*
  std::vector<double> probs = engine.get_probs();
  std::cout << "Probabilities:\n";
  for (auto p : probs) {
    std::cout << p << '\n';
  }
  
  ket psi = engine.get_psi();
  std::cout << "Final psi:\n";
  std::cout << disp(psi) << '\n';
  
  auto dits = engine.get_dits();
  std::cout << "Dits:\n";
  for (auto&& dit : dits) {
    std::cout << disp(dit) << '\n';
  }
  */  
}

