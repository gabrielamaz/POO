// matrix.h (header file)

#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  // numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const double &value = 0.0);
        Matrix(ifstream &myFile);
        Matrix(const Matrix &that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        double get(int row, int col) const; 

        // set
        void set(int row, int col, double value) const; 
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();

        // funções de sobrecarga
        Matrix operator ~ () const;               // igual a transposta
        Matrix operator + (const Matrix &) const; // Soma
        Matrix operator - (const Matrix &) const; // Subtração
        Matrix operator * (const Matrix &) const; // multiplicação de matrize
        void operator =  (const Matrix &) const; 
        void operator += (const Matrix &) const; // Soma
        void operator -= (const Matrix &) const; // Subtração
        void operator *= (const Matrix &) const; // multiplicação de matrizes
        void operator *= (const int&) const;     // multiplicação por uma constante
        double& operator () (int a, int b);      // altera o valor de uma posição
        bool operator == (const Matrix &);       // verifica a igualdade entre duas matrizes
        bool operator != (const Matrix &);       // verifica a desigualdade entre duas matrizes
        friend ostream& operator << (ostream &, Matrix &); // impressão de matrizes
        friend istream& operator >> (istream &, Matrix &); // leitura de dados para dentro da matriz Y
};