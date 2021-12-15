// matrix.h (header file)

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  // numero de colunas

    public:

        // Construtores
        Matrix<T>();                           
        Matrix<T>(int rows, int cols, const T &value = 0.0);
        Matrix<T>(ifstream &myFile);
        Matrix<T>(const Matrix<T> &that);
        // destrutor
        ~Matrix<T>();
    
        // basic getters
        int rows() const;
        int cols() const;
        T get(int row, int col) const; 

        // set
        void set(int row, int col, T value) const; 
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();

        // funções de sobrecarga
        Matrix<T> operator ~ () const;               // igual a transposta
        Matrix<T> operator + (const Matrix<T> &) const; // Soma
        Matrix<T> operator - (const Matrix<T> &) const; // Subtração
        Matrix<T> operator * (const Matrix<T> &) const; // multiplicação de matrize
        void operator =  (const Matrix<T> &) const; 
        void operator += (const Matrix<T> &) const; // Soma
        void operator -= (const Matrix<T> &) const; // Subtração
        void operator *= (const Matrix<T> &) const; // multiplicação de matrizes
        void operator *= (const int&) const;     // multiplicação por uma constante
        T& operator () (int a, int b);      // altera o valor de uma posição
        bool operator == (const Matrix<T> &);       // verifica a igualdade entre duas matrizes
        bool operator != (const Matrix<T> &);       // verifica a desigualdade entre duas matrizes
        friend ostream& operator << (ostream &, Matrix &); // impressão de matrizes
        friend istream& operator >> (istream &, Matrix &); // leitura de dados para dentro da matriz Y
};