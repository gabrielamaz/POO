#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <vector>

#include "Pessoa.hpp"
#include "Amigo.hpp"
#include "Conhecido.hpp"

class Agenda {
  public:
    Agenda(int numeroContatos) {
      contatos.reserve(numeroContatos);
      for(int i = 0; i < numeroContatos; i++) {
        contatos.push_back(criaPessoaAleatoria());
      }
    };

 private:
  int numeroAmigos;
  int numeroConhecidos;
  vector<Pessoa*> contatos;

  Pessoa* criaPessoaAleatoria() {
    int tipo;
    tipo = rand() % 2 + 1;
    if (tipo == 1){
      return new Amigo();
    } else {
      return new Conhecido();
    }
  };
};

#endif