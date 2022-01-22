#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

using namespace std;
class Pessoa {
 public:
  Pessoa() : nome("indefinido"), idade(0){};
  Pessoa(string nome, int idade) {
    nome = nome;
    idade = idade;
  };

 protected:
  string nome;
  int idade;
};

#endif