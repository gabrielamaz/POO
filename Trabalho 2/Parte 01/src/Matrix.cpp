// matrix.cpp
#include "Matrix.hpp"

#define ELEMSWAP(x, y) (x += y, y = x - y, x -= y)

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix() {
  this->nRows = 0;
  this->nCols = 0;
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem) {
  this->nRows = rows;
  this->nCols = cols;

  this->m = new double*[rows];
  for (int i = 0; i < rows; i++) {
    this->m[i] = new double[cols];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      this->m[i][j] = elem;
    }
  }
}

// destrutor
Matrix::~Matrix() {
  for (int i = 0; i < this->nCols; i++) {
    delete[] this->m[i];
  }
  delete[] this->m;
}

// obtem o numero de linhas
int Matrix::getRows() const { return this->nRows; }

// obtem o numero de colunas
int Matrix::getCols() const { return this->nCols; }

// retorna uma matriz transposta
Matrix Matrix::transpose() {
  Matrix Y(this->nCols, this->nRows);

  Y.m = new double *[Y.nRows];

  for (int i = 0; i < Y.nRows; i++) Y.m[i] = new double[Y.nCols];

  for (int i = 0; i < Y.nRows; i++) {
    for (int j = 0; j < Y.nCols; j++) {
      Y.m[i][j] = this->m[j][i];
    }
  }

  return Y;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            cout << this->m[i][j] << " ";
        }
        cout << endl;
    }
}