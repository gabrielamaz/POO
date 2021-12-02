#include <fstream>
#include <iostream>

#include "matrix.h"

using namespace std;

int main() {
  ifstream in("myMatrix.txt");
  Matrix Y;
  cout << "Matriz Y:" << endl;
  Y.print();
  Matrix X(3, 1);
  cout << "Matriz X:" << endl;
  X.print();
  Matrix Z(3, 2, 7.0);
  cout << "Matriz Z:" << endl;
  Z.print();
  Matrix W(in);
  cout << "Matriz W:" << endl;
  W.print();

  return 0;
}