#ifndef PROF_INTEGRAL_HPP
#define PROF_INTEGRAL_HPP

#include <string>

#include "Professor.hpp"

using namespace std;

class ProfIntegral : public Professor {
 private:
  double salarioMensal;

 public:
  ProfIntegral(string nome, double sm) : Professor(nome) {
    salarioMensal = sm;
  };
  double getSalario() override { return salarioMensal; };
  virtual ~ProfIntegral() {}
};

#endif