#include "Amigo.hpp"

void Amigo::editaInformacoes() {
  cout << "Digite as informações do seu Amigo: " << endl;
  Pessoa::editaInformacoes();
  cout << "Digite a data de aniversário: " << endl;
  cin >> dataAniversario;
}

void Amigo::imprimeInformacoes() {
  cout << "Data Aniversario: " << dataAniversario << endl;
}