#ifndef ERRO_H_
#define ERRO_H_

#include <iostream>
#include <string>

using namespace std;

class Erro {
 private:
  string tipoErro;

 public:
  Erro(const string &tipoErro_) : tipoErro(tipoErro_){};
  void out() { cout << tipoErro; }
};

#endif