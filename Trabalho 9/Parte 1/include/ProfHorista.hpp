#ifndef PROF_HORISTA_HPP
#define PROF_HORISTA_HPP

#include <string>

#include "Professor.hpp"

using namespace std;

class ProfHorista : public Professor {
  double nrHorasTrabalhadas;
  double valorHora;

 public:
  ProfHorista(string nome, double nht, double vh) : Professor(nome) {
    nrHorasTrabalhadas = nht;
    valorHora = vh;
  };
  double getSalario() override { return nrHorasTrabalhadas * valorHora; };
  virtual ~ProfHorista() {};
};

#endif