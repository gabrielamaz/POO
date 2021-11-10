#include <iostream>
#include "Tempo.hpp"

using namespace std;

int main() {
    int escolha = 0, aux = 0;
    Tempo *T = new Tempo();
    Tempo* t1 = new Tempo();

    cout << "Digite os dados pedidos." << endl << endl;
    T->leitura();
    cout << endl;
    T->escrita();
    cout << endl;

    while(1){
        cout << "Agora escolha uma das opcoes" << endl;
        cout << "1. SetDia \t2. SetHora \t3. SetMinuto \t4. SetSegundo" << endl;
        cout << "5. GetDia \t6. GetHora \t7. GetMinuto \t8. GetSegundo" << endl;
        cout << "9. SomarTempo \t10. Exit" << endl << endl << "Escolha:";
        cin >> escolha;
        cout << endl;
        switch (escolha)
        {
        case 1:
            cout << "Digite o valor: ";
            cin >> aux;
            T->setDia(aux);
            T->escrita();
            cout << endl;
            break;
        case 2:
            cout << "Digite o valor: ";
            cin >> aux;
            T->setHora(aux);
            T->escrita();
            cout << endl;
            break;
        case 3:
            cout << "Digite o valor: ";
            cin >> aux;
            T->setMin(aux);
            T->escrita();
            cout << endl;
            break;
        case 4:
            cout << "Digite o valor: ";
            cin >> aux;
            T->setSeg(aux);
            T->escrita();
            cout << endl;
            break;
        case 5:
            cout << T->getDia() << endl << endl;
            break;
        case 6:
            cout << T->getHora() << endl << endl;
            break;
        case 7:
            cout << T->getMin() << endl << endl;
            break;
        case 8:
            cout << T->getSeg() << endl << endl;
            break;
        case 9:
            cout << "Digite os dados pedidos." << endl << endl;
            t1->leitura();
            cout << endl;
            t1->escrita();
            cout << endl;
            
            T->somaTempo(*t1);
            t1->~Tempo();

            cout << "tempo resultante: ";
            T->escrita();
            cout << endl;
            break;
        case 10:
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}