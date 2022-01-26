#ifndef AMIGO_HPP
#define AMIGO_HPP

#include <iostream>
#include <string>

#include "Pessoa.hpp"

using namespace std;
class Amigo : public Pessoa {
 public:
  Amigo() : Pessoa(), dataAniversario("indefinida") {};
  string getAniversario() { return dataAniversario; };
  void editaInformacoes();
  void imprimeInformacoes();

 private:
  string dataAniversario;
};

#endif