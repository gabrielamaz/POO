#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    cout << "Matriz Y:" << endl;
    Y.print();
    cout << "Matriz X:" << endl;
    X.print();
    cout << "Matriz Z:" << endl; 
    Z.print();
    cout << "Matriz W:" << endl;
    W.print();

    

    return 0;
}