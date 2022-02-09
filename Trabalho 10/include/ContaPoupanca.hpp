#ifndef CONTA_POUPANCA_HPP
#define CONTA_POUPANCA_HPP

#include "ContaBancaria.hpp"

class ContaPoupanca : public ContaBancaria {
 private:
  double _taxaRendimento;

 public:
  ContaPoupanca(int senha, int numeroConta, double saldo, double taxaRendimento)
      : ContaBancaria(senha, numeroConta, saldo),
        _taxaRendimento(taxaRendimento) {}
        
};

#endif