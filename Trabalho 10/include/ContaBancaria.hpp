#ifndef CONTA_BANCARIA_HPP
#define CONTA_BANCARIA_HPP

#include <iostream>

class ContaBancaria {
 private:
  int _senha;
  int _numeroConta;
  double _saldo;

 public:
  ContaBancaria(int senha, int numeroConta, double saldo = 0.0)
      : _numeroConta(numeroConta), _senha(senha), _saldo(saldo) {}
  virtual ~ContaBancaria() {}
  int getSenha() { return _senha; }
  void setSenha(int senha) { _senha = senha; }
  int getNumeroConta() { return _numeroConta; }
  void setNumeroConta(int numeroConta) { _numeroConta = numeroConta; }
  double getSaldo() { return _saldo; }
  void setSaldo(double saldo) { _saldo = saldo; }
  virtual void saca(double valor) { _saldo -= valor; }
  virtual void deposita(double valor) { _saldo += valor; }
  virtual void tiraExtrato() {}
};

#endif