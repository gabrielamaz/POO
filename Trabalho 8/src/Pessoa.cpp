#include "Pessoa.hpp"

Pessoa::~Pessoa() {}

void Pessoa::editaInformacoes() {
  cout << "Digite o nome: " << endl;
  cin >> nome;
  cout << "Digite a idade: " << endl;
  cin >> idade;
}