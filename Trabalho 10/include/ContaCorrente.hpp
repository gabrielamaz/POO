#ifndef CONTA_CORRENTE_HPP
#define CONTA_CORRENTE_HPP

#include "ContaBancaria.hpp"

class ContaCorrente : public ContaBancaria {
 private:
  int _numeroTransacoes;

 public:
  ContaCorrente(int senha, int numeroConta, double saldo)
      : ContaBancaria(senha, numeroConta, saldo), _numeroTransacoes(0) {}
};

#endif