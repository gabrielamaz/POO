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
  virtual void saca(double valor) {}
  virtual void deposita(double valor) {}
  virtual void tiraExtrato() {}

  void alterarSenha(){
    int senha = -1;
    //std::cout << "Sua senha atual eh: " << getSenha() << std::endl;
    while((senha%_senha) != 0){
      std::cout << "Digite a senha atual: " << std::endl;
      std::cin >> senha;
    }
    std::cout << "Digite a nova senha: ";
    std::cin >> senha;
    setSenha(senha);
  }
};

#endif