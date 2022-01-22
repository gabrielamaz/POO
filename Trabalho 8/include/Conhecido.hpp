#ifndef CONHECIDO_HPP
#define CONHECIDO_HPP

#include <string>

#include "Pessoa.hpp"

using namespace std;
class Conhecido : public Pessoa {
 public:
  Conhecido() : email("indefinido"), Pessoa(){};

  void imprimeInformacoes() {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
  }
  void editaInformacoes() override {
    cout << "Digite as informações do seu Conhecido: " << endl;
    Pessoa::editaInformacoes();
    cout << "Digite o e-mail:" << endl;
    cin >> email;
  };

 private:
  string email;
};

#endif