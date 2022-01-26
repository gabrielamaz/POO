#include "Agenda.hpp"

Agenda::Agenda(int numeroContatos) {
  contatos.reserve(numeroContatos);
  for (int i = 0; i < numeroContatos; i++) {
    contatos.push_back(criaPessoaAleatoria());
  }
}

Agenda::~Agenda() {
  for (auto const& contato : contatos) {
    delete contato;
  }
}

void Agenda::addInformacoes() {
  for (auto const& contato : contatos) {
    contato->editaInformacoes();
  }
}

Pessoa* Agenda::criaPessoaAleatoria() {
  int tipo;
  tipo = rand() % 2 + 1;
  if (tipo == 1) {
    return new Amigo();
  } else {
    return new Conhecido();
  }
}

void Agenda::imprimeAniversarios() {
  for (auto const& contato : contatos) {
    if (typeid(*contato) == typeid(Amigo)) {
      contato->imprimeInformacoes();
    }
  }
}

void Agenda::imprimeEmails() {
  for (auto const& contato : contatos) {
    if (typeid(*contato) == typeid(Conhecido)) {
      contato->imprimeInformacoes();
    }
  }
}