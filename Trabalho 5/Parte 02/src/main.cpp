#include <iostream>
#include <fstream>
#include "matriz.h"

using namespace std;

int main()
{
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1,2.0), A(3,3,2.0), C(3,3);
    Matrix Z(3,2,7.0);
    // Matrix W(in);
    
    // operadores a serem implementados em sua classe:

    //A(2, 1) = 10;              // altera o valor de uma posição de A
    C = A + A;                 // Soma
    cout << "C = A + A" << endl;
    cout << C << endl;
    C -= A;                    // Subtração
    cout << "C -= A" << endl;
    cout << C << endl;
    A = C - A;                 // Subtração
    cout << "A = C - A" << endl;
    cout << A << endl;
    A += A;                    // Soma
    cout << "A += A" << endl;
    cout << A << endl;
    //A = ~C;                    // A é igual a transposta de C
    cout << X << endl;
    X *= 2;                    // multiplicação por uma constante
    cout << "X *= 2" << endl;
    cout << X << endl;
    // C = A * X;                 // multiplicação de matrizes
    // cout << C << endl;
    C *= X;                    // multiplicação de matrizes
    cout << "C *= x" << endl;
    cout << C << endl;
    if (A == C)                // verifica a igualdade entre A e C
    cout << "A == C" << endl;
    cout << (A==C) << endl;
    if (X != Y)                // verifica a desigualdade entre A e C
    cout << "X != Y" << endl;
    cout << (X!=Y) << endl;
    cout << "Z" << endl;
    cout << Z << endl;         // impressão de matrizes
    //cin >> W;                  // leitura de dados para dentro da matriz Y

    return 0;
}