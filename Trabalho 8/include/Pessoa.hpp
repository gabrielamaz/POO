#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;
class Pessoa {
 public:
  Pessoa() : nome("indefinido"), idade(0){};
  Pessoa(string nome, int idade) {
    nome = nome;
    idade = idade;
  };

  virtual ~Pessoa();

  virtual void imprimeInformacoes()  = 0;

  virtual void editaInformacoes();

 protected:
  string nome;
  int idade;
};

#endif