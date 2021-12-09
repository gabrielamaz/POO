// matrix.cpp
#include "matriz.h"
#include <fstream>

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix() {
  this->nRows = 0;
  this->nCols = 0;
  this->m = nullptr;
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols, const double &value) {
  this->nRows = rows;
  this->nCols = cols;
  this->m = new double *[nRows];
  for (int i = 0; i < nRows; ++i) m[i] = new double[nCols];

  for (int i = 0; i < nRows; ++i) {
    for (int j = 0; j < nCols; ++j) {
      m[i][j] = value;
    }
  }
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo
// arquivo texto myFile.
Matrix::Matrix(ifstream &myFile) {
  if (!myFile.is_open()) {
    cout << "Error: nao foi possivel abrir o arquivo" << endl;
    exit(1);
  }
  myFile >> nRows;
  myFile >> nCols;

  this->m = new double *[nRows];
  for (int i = 0; i < nRows; i++) m[i] = new double[nCols];
  for (int i = 0; i < nCols; i++) {
    for (int j = 0; j < nCols; j++) {
      myFile >> m[i][j];
    }
  }
  myFile.close();
}

// contrutor de copia
Matrix::Matrix(const Matrix &that) {
  nRows = that.nRows;
  nCols = that.nCols;
  for (int i = 0; i < this->nRows; ++i) {
    for (int j = 0; j < this->nCols; ++j) {
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

// obtem um elemento específico na posição (row,col). Obs: deve checar
// consistencia
double Matrix::get(int row, int col) const {
  if (row < 0 || row > nRows) {
    cout << "numero escolhido para linha invalido.";
  } else if (col < 0 || col > nCols) {
    cout << "numero escolhido para coluna invalido.";
  } else
    return this->m[nRows][nCols];
}

// imprime o conteudo da matriz
void Matrix::print() const {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      cout << this->m[i][j] << " ";
    }
    cout << endl;
  }
}

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit() {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      if (i != j)
        this->m[i][j] = 0;
      else
        this->m[i][j] = 1;
    }
  }
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros() {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      this->m[i][j] = 0;
    }
  }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
void Matrix::ones() {
  for (int i = 0; i <= this->nRows; i++) {
    for (int j = 0; j <= this->nCols; j++) {
      this->m[i][j] = 1;
    }
  }
}

// altera o valor de uma posição
Matrix Matrix::operator=(const Matrix &a) const{
  Matrix temp(a.getRows(), a.getCols());
  for(int i = 0; i < temp.getRows(); i++){
    for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = a.m[i][j];
  }
  return temp;
} 

// soma
Matrix Matrix::operator+(const Matrix &a) const{
  Matrix temp(nRows, nCols);
  if((temp.getRows() == a.getRows()) && (temp.getCols() == a.getCols())){
    for(int i = 0; i < temp.getRows(); i++){
      for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = m[i][j] + a.m[i][j];
    }
    return temp;
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
}  

// Subtração
Matrix Matrix::operator-=(const Matrix &a) const {
  Matrix temp(nRows, nCols);
  if((temp.getRows() == a.getRows()) && (temp.getCols() == a.getCols())){
    for(int i = 0; i < temp.getRows(); i++){
      for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = m[i][j] - a.m[i][j];
    }
    return temp;
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
} 

// Subtração
Matrix Matrix::operator-(const Matrix &a) const{
  Matrix temp(nRows, nCols);
  if((temp.getRows() == a.getRows()) && (temp.getCols() == a.getCols())){
    for(int i = 0; i < temp.getRows(); i++){
      for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = m[i][j] - a.m[i][j];
    }
    return temp;
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
} 

// Soma
Matrix Matrix::operator+=(const Matrix &a) const{
  Matrix temp(nRows, nCols);
  if((temp.getRows() == a.getRows()) && (temp.getCols() == a.getCols())){
    for(int i = 0; i < temp.getRows(); i++){
      for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = m[i][j] + a.m[i][j];
    }
    return temp;
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
} 

// igual a transposta
// Matrix Matrix::operator~(){

// } 

// multiplicação por uma constante
Matrix Matrix::operator*=(const int &b) const{
  Matrix temp(nRows, nCols);
  for(int i = 0; i < temp.getRows(); i++){
    for(int j = 0; j < temp.getCols(); j++) temp.m[i][j] = m[i][j] * b;
  }
  return temp;
} 

// multiplicação de matrizes
Matrix Matrix::operator*(const Matrix &a) const{
  if(nCols == a.getRows()){
    Matrix temp(nCols, a.getRows());
    for(int i = 0; i < temp.getRows(); i++){
      double position = 0;
      for(int j = 0; j < temp.getCols(); j++){
        for(int k = 0; k < a.getCols(); k++){
          position += m[i][k]*a.m[k][j];
        }
        temp.m[i][j] = position;
      }
    }
  }else{
     cout << "Nao eh possivel fazer a multiplicacao" << endl;
  }
} 

// multiplicação de matrizes
Matrix Matrix::operator*=(const Matrix &a) const{
  if(nCols == a.getRows()){
    Matrix temp(nCols, a.getRows());
    for(int i = 0; i < temp.getRows(); i++){
      double position = 0;
      for(int j = 0; j < temp.getCols(); j++){
        for(int k = 0; k < a.getCols(); k++){
          position += m[i][k]*a.m[k][j];
        }
        temp.m[i][j] = position;
      }
    }
  }else{
     cout << "Nao eh possivel fazer a multiplicacao" << endl;
  }
} 

// verifica a desigualdade entre duas matrizes
bool Matrix::operator==(const Matrix &a){
  if((nRows == a.getRows()) || (nCols != a.getCols())){
    int aux = 0;
    for(int i = 0; i <= a.getRows(); i++){
      for(int j = 0; j <= a.getCols(); j++){
        if(m[i][j] != a.m[i][j]){
          aux++;
          return false;
        }
      }
    }
    if(aux == 0) return true;
  }else return false;
} 

// verifica a desigualdade entre duas matrizes
bool Matrix::operator!=(const Matrix &b){
  if((nRows != b.getRows()) || (nCols != b.getCols())) return true;
  else{
    for(int i = 0; i <= b.getRows(); i++){
      int aux = 0;
      for(int j = 0; j <=  b.getCols(); j++){
        if(m[i][j] != b.m[i][j]){
          aux++;
          return true;
        }
      }
      if(aux == 1) break;
    }
  }
} 

// impressão de matrizes
ostream& operator << (ostream &out, Matrix &a){
  for(int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++){
      cout << a.m[i][j] << " ";
    }
    cout << endl;
  }
  return out;
} 

// leitura de dados para dentro da matriz Y
// istream& operator>>(Matrix &l){
  
// }