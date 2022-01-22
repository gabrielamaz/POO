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

  void imprimeInformacoes() {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
  }

  virtual void editaInformacoes() {
    cout << "Digite o nome do seu Contato: " << endl;
    cin >> nome;
    cout << "Digite a idade do seu contato: " << endl;
    cin >> idade;
  };

 protected:
  string nome;
  int idade;
};

#endif