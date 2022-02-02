#ifndef UNIVERSIDADE_HPP
#define UNIVERSIDADE_HPP

#include <vector>

#include "Professor.hpp"

using namespace std;
class Universidade {
  private:
    vector<Professor*> professores;
  public:
    Universidade() {};
    ~Universidade() {};
    void addProfessor(Professor* const & prof);
    double totalPago();
};

#endif