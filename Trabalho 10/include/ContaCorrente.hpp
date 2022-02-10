#ifndef CONTA_CORRENTE_HPP
#define CONTA_CORRENTE_HPP

#include <iostream>
#include "ContaBancaria.hpp"

class ContaCorrente : public ContaBancaria {
 private:
  int _numeroTransacoes = 0;

 public:
    ContaCorrente(int senha, int numeroConta, double saldo)
        : ContaBancaria(senha, numeroConta, saldo), _numeroTransacoes(0) {}

    int getTansacoes(){ return _numeroTransacoes; }
    
    virtual void saca(double valor){
        int saldoAtual = getSaldo();
        
        if((getSaldo() != 0) && (getSaldo() - valor >= 0)){
            saldoAtual -= valor;
            setSaldo(saldoAtual);
            _numeroTransacoes++;
        }else{
            std::cout << "Valor indisponivel, o valor maximo que pode ser sacado eh: " << getSaldo() << std::endl;
        }
    }

    virtual void depositar(double valor){
        int saldoAtual = getSaldo();
        saldoAtual += valor;
        setSaldo(saldoAtual);
        _numeroTransacoes++;
    }

    virtual void tiraExtrato(){
        std::cout << "Numero da conta: "      << getNumeroConta()  << std::endl;
        std::cout << "Saldo: "                << getSaldo()        << std::endl;
        std::cout << "Numero de transacoes: " << getTansacoes()    << std::endl;
    }
};

#endif