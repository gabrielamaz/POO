#include <iostream>
#include <vector>
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"

using namespace std;

int main() {

    int contas = 0;
    int poupanca = 0;
    int corrente = 0;
    int cont = 0;

    vector<ContaBancaria> Contas;

    cout << "Digitre o numero de contas a serem criadas: ";
    cin >> contas;
    do{
        cout << "Quantas delas sao contas correntes? ";
        cin >> corrente;
    }while((contas - corrente) < 0);
    
    if(contas - corrente != 0){
        do{
            cout << "Quantas delas sao contas poupanca? ";
            cin >> poupanca;
        }while((contas - corrente - poupanca) != 0);
    }

    for(cont = 0; cont < corrente; cont++){
        int senha = 0;
        int conta = 0;

        cout << "Digite o numero da sua conta corrente " << cont+1 << ": ";
        cin >> conta;
        
        cout << "Digiter a sua senha: ";
        cin >> senha;
        
        ContaBancaria *contaCorrente = new ContaCorrente(senha, conta, 0);
        Contas.push_back(*contaCorrente);
    }

    for(cont = 0; cont < poupanca; cont++){
        int senha = 0;
        int conta = 0;

        cout << "Digite o numero da sua conta poupanca " << cont+1 << ": ";
        cin >> conta;

        cout << "Digiter a sua senha: ";
        cin >> senha;

        ContaBancaria *contaPoupanca = new ContaPoupanca(senha, conta, 0, 0.1);
        Contas.push_back(*contaPoupanca);
    }

    cout << "A taxa de rendimento da conta poupanca eh de 10%." << endl;

    //TODO: saque, depositos e extratos
    while(1){
        int senha = 0;
        int conta = 0;
        bool valido = false;

        cout << "Digite a opcao desejada" << endl;
        cout << "1. Realizar um saque\t 2.Realizar um deposito\t 3.Exibir extrato\t 4.Alterar senha\t 5.Sair" << endl;
        cin >> cont;

        if(cont != 5){
            cout << "Digite o numero da conta: ";
            cin >> conta;

            //conferir se a conta existe
            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getNumeroConta() == conta){
                    valido = true;
                    break;
                }
            }

            if(valido == false){
                do{
                    cout << "Numero da conta invalido, tente novamente. Caso deseje sair prescione -1" << endl;
                    cin >> conta;
                    
                    //finaliza toda a operacao
                    if(conta == -1) exit(1);

                    //conferir se a conta existe
                    for(auto i = Contas.begin(); i != Contas.end(); i++){
                        if(i->getNumeroConta() == conta){
                            valido = true;
                            break;
                        }
                    }
                    
                }while(valido == false);
            }

            valido  = false;

            cout << "Digite a senha da sua conta: ";
            cin >> senha;
            //conferir se a senha existe
            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getSenha() == senha){
                    valido = true;
                    break;
                }
            }

            if(valido == false){
                do{
                    cout << "Senha invalida, tente novamente. Caso deseje sair prescione -1" << endl;
                    cin >> conta;

                    //finaliza toda a operacao
                    if(senha == -1) exit(1);
                    
                    //conferir se a conta existe
                    for(auto i = Contas.begin(); i != Contas.end(); i++){
                        if(i->getSenha() == senha){
                            valido = true;
                            break;
                        }
                    }
                    
                }while(valido == false);
            }
        }
        switch(cont)
        {
        case 1: 

            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getNumeroConta() == conta){
                    int valor = 0;
                    cout << "Digite o valor do saque a ser feito: ";
                    cin >> valor;
                    i->saca(valor);
                }
            }

            break;
        case 2:

            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getNumeroConta() == conta){
                    int valor = 0;
                    cout << "Digite o valor do depoisito a ser feito: ";
                    cin >> valor;
                    i->deposita(valor);
                }
            }

            break;
        case 3:

            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getNumeroConta() == conta){
                    i->tiraExtrato();
                }
            }

            break;
        case 4:

            for(auto i = Contas.begin(); i != Contas.end(); i++){
                if(i->getNumeroConta() == conta){
                    i->alterarSenha();
                }
            }

            break;
        case 5:
            break;
        }
    }

    //TODO: quantidade de transacoes e taxas de rendimentos

    return 0;
}