#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    cout << "Matriz Y:" << endl;
    Y.print();
    Matrix X(3,1);
    cout << "Matriz X:" << endl;
    X.print();
    Matrix Z(3,2,7.0);
    cout << "Matriz Z:" << endl; 
    Z.print();
    Matrix W(in);
    cout << "Matriz W:" << endl;

    cout << "Matriz Y:" << endl;
    Y.print();
    cout << "Matriz X:" << endl;
    X.print();
    cout << "Matriz Z:" << endl; 
    Z.print();
    cout << "Matriz W:" << endl;
    W.print();


    // while (1) {
    //     cout << "Agora escolha uma das opcoes" << endl;
    //     cout << "1. Imprimir ponto \t2. Criar outro ponto \t3. Distância até origem \t4. Criar uma copia"
    //             << endl;
    //     cout << "5. Distancia ao segundo ponto \t6. Somar com segundo ponto \t7. "
    //             "Imprimir IDs utilizados \t8. "
    //             "Sair"
    //             << endl;
    //     cin >> escolha;
    //     switch (escolha) {
    //         case 1:
    //             p1->print();
    //         break;
    //         case 2:
    //             p2->leitura();
    //             break;
    //         case 3:
    //             cout << p1->distToOrig() << endl;
    //             break;
    //         case 4:
    //             cout << "tipo de copia: \t1. Ponto p(p1) \t2. Ponto p = p1" << endl;
    //             break;
    //         case 5:
    //             cout << p1->distTo(*p2) << endl;
    //             break;
    //         case 6:
    //             p1->sumOf(*p2);
    //             p2->print();
    //             break;
    //         case 7:
    //             p1->printIds();
    //             break;
    //         case 8:
    //             p1->~Ponto2D();
    //             p2->~Ponto2D();
    //             exit(0);
    //             default:
    //             break;
    //         }
    //     }
    return 0;
}