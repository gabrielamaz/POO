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
  
  double getRendimento(){ return _taxaRendimento; }
  
  virtual void saca(double valor){
    int saldoAtual = getSaldo();
        
    if((getSaldo() != 0) && (getSaldo() - valor >= 0)){
      saldoAtual -= valor;
      setSaldo(saldoAtual);
    }else{
      std::cout << "Valor indisponivel, o valor maximo que pode ser sacado eh: " << getSaldo() << std::endl;
    }
    }

  virtual void depositar(double valor){
    int saldoAtual = getSaldo();
    saldoAtual += valor;
    setSaldo(saldoAtual);
  }

  virtual void tiraExtrato(){
    std::cout << "Numero da conta: "      << getNumeroConta()  << std::endl;
    std::cout << "Saldo: "                << getSaldo()        << std::endl;
    std::cout << "Taxa de Rendimento: "   << getRendimento()   << std::endl;
  }
        
};

#endif