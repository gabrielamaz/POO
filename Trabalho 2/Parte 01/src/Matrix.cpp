// matrix.cpp
#include "Matrix.hpp"

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix() {
    this->nRows = 0;
    this->nCols = 0; 
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem = 0.0){
    this->nRows = rows;
    this->nCols = cols;

    this->m = new double* [rows];
    for(int i = 0; i < rows; i++) {
        m[i] = new double [cols];
    }
}


// destrutor
Matrix::~Matrix() {
   
}


// obtem o numero de linhas
int Matrix::getRows() const {
    return this->nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return this->nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    
}

// imprime o conteudo da matriz
void Matrix::print() const {
    
}