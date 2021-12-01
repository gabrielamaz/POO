// matrix.cpp
#include "matrix.h"
#include <fstream>

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    this->nRows = 0;
    this->nCols = 0;
    this->m = nullptr;
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols, const double &value){ 
    this->nRows = rows;
    this->nCols = cols;
    this->m = new double *[nRows];
    for (int i = 0; i < nRows; i++) m[i] = new double[nCols];
        for (int i = 0; i < nCols; i++) {
            for (int j = 0; j < nCols; j++) {
                m[i][j] = value;
            }
        }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
Matrix::Matrix(fstream &myFile) {
    myFile.open("myFile");
    if(!myFile) {
      cout << "Error: nao foi possivel abrir o arquivo" << endl;
      exit(1);
    }
    myFile >> nRows;
    nCols = nRows;
    while ( !myFile.eof() ) {
        for(int i = 0; i < this->nRows; i++){
            for(int j = 0; j < this->nCols; j++){
                myFile >> m[i][j];
            }
        }
   }
   myFile.close();
}

// contrutor de copia
Matrix::Matrix(const Matrix &that){
    nRows = that.nRows;
    nCols = that.nCols;
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            that.m[i][j] = m[i][j];
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
int Matrix::getRows() const { return this->nCols; }

// obtem o numero de colunas
int Matrix::getCols() const { return this->nCols; }

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const { 
    if (row < 0 || row > nRows){
        cout << "numero escolhido para linha invalido.";
    }else if(col < 0 || col > nCols){
        cout << "numero escolhido para coluna invalido.";
    }else return this->m[row][col];
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

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            if(i != j)this->m[i][j] = 0;
            else this->m[i][j] = 1;
        }
    }
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 0;
        }
    }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
void Matrix::ones(){
    for(int i = 0; i < this->nRows; i++){
        for(int j = 0; j < this->nCols; j++){
            this->m[i][j] = 1;
        }
    }
}