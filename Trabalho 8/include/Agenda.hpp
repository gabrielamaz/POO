#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <vector>

#include "Pessoa.hpp"
#include "Amigo.hpp"
#include "Conhecido.hpp"

class Agenda {
  public:
    Agenda(int numeroContatos);

    ~Agenda();

    int getNumeroAmigos() {return numeroAmigos;};
    int getNumeroConhecidos() {return numeroConhecidos;};

    void addInformacoes();
    void imprimeAniversarios();
    void imprimeEmails();

    

 private:
  int numeroAmigos;
  int numeroConhecidos;
  vector<Pessoa*> contatos;

  Pessoa* criaPessoaAleatoria() ;
};

#endif