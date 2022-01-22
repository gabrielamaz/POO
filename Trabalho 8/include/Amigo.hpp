#ifndef AMIGO_HPP
#define AMIGO_HPP

#include <iostream>
#include <string>

#include "Pessoa.hpp"

using namespace std;
class Amigo : public Pessoa {
 public:
  Amigo() : Pessoa(){};
  void editaInformacoes() override {
    cout << "Digite as informações do seu Amigo: " << endl;
    Pessoa::editaInformacoes();
    cout << "Digite a data de aniversário: " << endl;
    cin >> dataAniversario;
  };
  void imprimeInformacoes() {
    Pessoa::imprimeInformacoes();
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
  }

 private:
  string dataAniversario;
};

#endif