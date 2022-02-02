#include "Universidade.hpp"

void Universidade::addProfessor(Professor* const &prof) {
  this->professores.push_back(prof);
}

double Universidade::totalPago() {
  double total = 0;
  double salario;
  for (auto const& professor : professores) {
    salario = professor->getSalario();
    total+= salario;
  }
  return total;
}