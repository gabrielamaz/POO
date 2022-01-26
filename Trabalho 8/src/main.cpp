#include <iostream>

#include "Agenda.hpp"
#include "Amigo.hpp"

int main() {
  int numContatos;
  cout << "Digite o número de contatos para a agenda: ";
  cin >> numContatos;

  Agenda* agenda = new Agenda(numContatos);

  agenda->addInformacoes();
  agenda->imprimeAniversarios();
  agenda->imprimeEmails();
  delete agenda;
}