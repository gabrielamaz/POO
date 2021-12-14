#include <cstdlib>  // system()
#include <iostream>
using namespace std;
#include "Erro.h"
#include "Fibonacci.h"
#include "List.h"

void clearscreen() {
  if (system("clear")) system("cls");
}

int main(int argc, char *argv[]) {
  // Cria Lista
  List<int> A;
  cout << "Criacao da Lista A:" << endl;
  cout << "-> Lista A: " << A << endl;

  // Insere elementos no Final da lista
  A.push_back(3);
  A.push_back(4);
  A.push_back(5);
  A.push_back(6);
  A.push_back(6);
  A.push_back(1);
  A.push_back(2);
  cout << "A.push_back(3), A.push_back(4), A.push_back(5), A.push_back(6), "
          "A.push_back(6), A.push_back(1), A.push_back(2)"
       << endl;
  cout << "-> Lista A " << A << endl;

  // Insere elementos no Inicio da lista
  A.push_front(8);
  A.push_front(9);
  A.push_front(4);
  A.push_front(9);
  cout << "A.push_front(8), A.push_front(9), A.push_front(4), A.push_front(9)"
       << endl;
  cout << "-> Lista A " << A << endl;

  // remove os elementos de valor igual a 6 existentes na lista
  try {
    A.erase(6);
    cout << "A.erase(6)" << endl;
    cout << "-> Lista A " << A << endl;
  } catch (Erro &err) {
    cout << "Exceção ocorrida: " << err.out() << endl;
  }

  // retorna o tamanho da lista
  int tam;
  tam = A.size();
  cout << "tam = A.size" << endl;
  cout << "-> tamanho da Lista A = " << tam << endl << endl;

  int ni = 2;
  int respi = Fibonacci<int>::calculateFibonacci(ni);
  cout << "Fibonacci int 2: " << respi << endl; 
  cout << typeid(respi).name() << endl;

  long nl = 3;
  long respl = Fibonacci<long>::calculateFibonacci(nl);
  cout << "Fibonacci int 3: " << respl << endl; 
  cout << typeid(respl).name() << endl;

  float nf = 4;
  float respf = Fibonacci<float>::calculateFibonacci(nf);
  cout << "Fibonacci float 4: " << respf << endl; 
  cout << typeid(respf).name() << endl;

  double nd = 5;
  double respd = Fibonacci<double>::calculateFibonacci(nd);
  cout << "Fibonacci double 5: " << respd << endl; 
  cout << typeid(respd).name() << endl;

  cout << "\nPressione qualquer tecla para continuar...";
  getchar();
  clearscreen();
}