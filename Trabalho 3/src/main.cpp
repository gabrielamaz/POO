#include <iostream>

#include "Ponto2D.hpp"

using namespace std;

int main() {
  int escolha = 0;
  Ponto2D *p1 = new Ponto2D();
  Ponto2D *p2 = new Ponto2D();
  p1->leitura();

  while (1) {
    cout << "Agora escolha uma das opcoes" << endl;
    cout << "1. Imprimir ponto \t2. Criar outro ponto \t3. Distância até origem"
         << endl;
    cout << "4. Distancia ao segundo ponto \t5. Somar com segundo ponto \t6. "
            "Imprimir IDs utilizados \t7. "
            "Sair"
         << endl;
    cin >> escolha;
    switch (escolha) {
      case 1:
        p1->print();
        break;
      case 2:
        p2->leitura();
        break;
      case 3:
        cout << p1->distToOrig() << endl;
        break;
      case 4:
        cout << p1->distTo(*p2) << endl;
        break;
      case 5:
        p1->sumOf(*p2);
        p2->print();
        break;
      case 6:
         p1->printIds();
        break;
      case 7:
        p1->~Ponto2D();
        p2->~Ponto2D();
        exit(0);
      default:
        break;
    }
  }
}