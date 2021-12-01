#include <iostream>

#include "Ponto2D.hpp"

using namespace std;

int main() {
  int escolha = 0;
  Ponto2D *p1 = new Ponto2D();
  Ponto2D *p2 = new Ponto2D();
  p1->leitura();

// // formas usuais (já implementadas)
// Ponto2D p1;             
// Ponto2D p2(3.0, 4.0);   

// // inicializações usando o construtor de cópia
// Ponto2D p3(p1);      // Ponto2D p3 é inicializad         o com as coordenadas do ponto p1
// Ponto2D p4 = p2;     // Ponto2D p4 é inicializado com as coordenadas do ponto p2

  while (1) {
    cout << "Agora escolha uma das opcoes" << endl;
    cout << "1. Imprimir ponto \t2. Criar outro ponto \t3. Distância até origem \t4. Criar uma copia"
         << endl;
    cout << "5. Distancia ao segundo ponto \t6. Somar com segundo ponto \t7. "
            "Imprimir IDs utilizados \t8. "
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
        cout << "tipo de copia: \t1. Ponto p(p1) \t2. Ponto p = p1" << endl;
        
        break;
      case 5:
        cout << p1->distTo(*p2) << endl;
        break;
      case 6:
        p1->sumOf(*p2);
        p2->print();
        break;
      case 7:
         p1->printIds();
        break;
      case 8:
        p1->~Ponto2D();
        p2->~Ponto2D();
        exit(0);
      default:
        break;
    }
  }
}