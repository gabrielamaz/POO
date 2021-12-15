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

// construtor default - cria uma matriz vazia com nRows = nCols = 0
template <class T>
Matrix<T>::Matrix() {
  this->nRows = 0;
  this->nCols = 0;
  this->m = nullptr;
}

// construtor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a 0.0 (double)
template <class T>
Matrix<T>::Matrix(int rows, int cols, const T &value) {
  this->nRows = rows;
  this->nCols = cols;
  this->m = new T *[nRows];
  for (int i = 0; i < nRows; ++i) m[i] = new T[nCols];

  for (int i = 0; i < nRows; ++i) {
    for (int j = 0; j < nCols; ++j) {
      m[i][j] = value;
    }
  }
}


// construtor parametrico 2 - cria uma matriz com os dados fornecidos pelo
// arquivo texto myFile.
template <class T>
Matrix<T>::Matrix(ifstream &myFile) {
  if (!myFile.is_open()) {
    cout << "Error: nao foi possivel abrir o arquivo" << endl;
    exit(1);
  }
  myFile >> nRows;
  myFile >> nCols;

  this->m = new T *[nRows];
  for (int i = 0; i < nRows; i++) m[i] = new T [nCols];
  for (int i = 0; i < nCols; i++) {
    for (int j = 0; j < nCols; j++) {
      myFile >> m[i][j];
    }
  }
  myFile.close();
}

// construtor de copia
template <class T>
Matrix<T>::Matrix(const Matrix<T> &that) {
  this->nRows = that.nRows;
  this->nCols = that.nCols;
  this->m = new T *[nRows];
  for (int i = 0; i < nRows; ++i) m[i] = new T[nCols];

  for (int i = 0; i < this->nRows; ++i) {
    for (int j = 0; j < this->nCols; ++j) {
      that.m[i][j] = m[i][j];
    }
  }
}


// destrutor
template <class T>
Matrix<T>::~Matrix() {
  for (int i = 0; i < this->nCols; i++) {
    delete[] this->m[i];
  }
  delete[] this->m;
}


// obtem o numero de linhas
template <class T>
int Matrix<T>::rows() const { return this->nRows; }

// obtem o numero de colunas
template <class T>
int Matrix<T>::cols() const { return this->nCols; }

// obtem um elemento específico na posição (row,col). Obs: deve checar
// consistencia
template <class T>
T Matrix<T>::get(int row, int col) const {
  if (row < 0 || row > nRows) {
    cout << "numero escolhido para linha invalido.";
  } else if (col < 0 || col > nCols) {
    cout << "numero escolhido para coluna invalido.";
  } else
    return this->m[nRows][nCols];
}



// imprime o conteudo da matriz
template <class T>
void Matrix<T>::print() const {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      cout << this->m[i][j] << " ";
    }
    cout << endl;
  }
}


// faz com que a matriz torne-se uma matriz identidade
//TODO #1 continuar unit?
template <class T>
void Matrix<T>::unit() {
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
template <class T>
void Matrix<T>::zeros() {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      this->m[i][j] = 0;
    }
  }
}


// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
template <class T>
void Matrix<T>::ones() {
  for (int i = 0; i < this->nRows; i++) {
    for (int j = 0; j < this->nCols; j++) {
      this->m[i][j] = 1;
    }
  }
}


template <class T>
void Matrix<T>::operator=(const Matrix<T> &a) const{
  for(int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++) m[i][j] = a.m[i][j];
  }
}


// altera o valor de uma posição
template <class T>
 T& Matrix<T>::operator() (int a, int b){
    return m[a][b];
 }

 // soma
 template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &a) const{
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
template <class T>
void Matrix<T>::operator-=(const Matrix<T> &a) const {
  if((nRows == a.getRows()) && (nCols == a.getCols())){
    for(int i = 0; i < nRows; i++){
      for(int j = 0; j < nCols; j++) m[i][j] = m[i][j] - a.m[i][j];
    }
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
}


// Subtração
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &a) const{
  Matrix<T> temp(nRows, nCols);
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
template <class T>
void Matrix<T>::operator+=(const Matrix<T> &a) const{
  if((nRows == a.getRows()) && (nCols == a.getCols())){
    for(int i = 0; i < nRows; i++){
      for(int j = 0; j < nCols; j++) m[i][j] = m[i][j] + a.m[i][j];
    }
  }else{
    cout << "Matrizes de tamanhos diferentes, nao eh possivel fazer a subtracao" << endl;
  }
}

//igual a transposta
template <class T>
Matrix<T> Matrix<T>::operator~()const{
  Matrix temp(nCols, nRows);
  for(int i = 0; i < nRows; i++){
    for(int j = 0; j < nCols; j++){
      temp.m[j][i] = m[i][j]; 
    }
  }
  return temp;
} 

// multiplicação por uma constante
template <class T>
void Matrix<T>::operator*=(const int &b) const{
  for(int i = 0; i < nRows; i++){
    for(int j = 0; j < nCols; j++) m[i][j] = m[i][j] * b;
  }
} 

// multiplicação de matrizes
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &a) const{
  if(nCols == a.getRows()){
    Matrix<T> temp(nCols, a.getRows());
    for(int i = 0; i < temp.getRows(); i++){
      double position = 0;
      for(int j = 0; j < temp.getRows(); j++){
        for(int k = 0; k < a.getCols(); k++){
          position += m[i][k] * a.m[k][j];
        }
        temp.m[i][j] = position;
      }
    }
    return temp;
  }else{
     cout << "Nao eh possivel fazer a multiplicacao" << endl;
  }
} 

// multiplicação de matrizes
template <class T>
void Matrix<T>::operator*=(const Matrix<T> &a) const{
  if(nCols == a.getRows()){
    for(int i = 0; i < nRows; i++){
      double position = 0;
      for(int j = 0; j < nCols; j++){
        for(int k = 0; k < a.getCols(); k++){
          position += m[i][k]*a.m[k][j];
        }
        m[i][j] = position;
      }
    }
  }else{
     cout << "Nao eh possivel fazer a multiplicacao" << endl;
  }
} 

// verifica a desigualdade entre duas matrizes
template <class T>
bool Matrix<T>::operator==(const Matrix<T> &a){
  if((nRows == a.getRows()) || (nCols != a.getCols())){
    int aux = 0;
    for(int i = 0; i < a.getRows(); i++){
      for(int j = 0; j < a.getCols(); j++){
        if(m[i][j] != a.m[i][j]){
          aux++;
          return false;
        }
      }
    }
    if(aux == 0) return true;
  } else return false;
} 


// verifica a desigualdade entre duas matrizes
template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &b){
  if((nRows != b.getRows()) || (nCols != b.getCols())) return true;
  else{
    for(int i = 0; i < b.getRows(); i++){
      int aux = 0;
      for(int j = 0; j <  b.getCols(); j++){
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
template <class T>
ostream& operator << (ostream &out, Matrix<T> &a){
  for(int i = 0; i < a.getRows(); i++){
    for(int j = 0; j < a.getCols(); j++){
      cout << a.m[i][j] << " ";
    }
    cout << endl;
  }
  return out;
} 


// leitura de dados para dentro da matriz Y
template <class T>
istream& operator>>(istream &in, Matrix<T> &l){
  cin >> l.nRows;
  cin >> l.nCols;
  l.m = new T *[l.nRows];
  for (int i = 0; i < l.nRows; ++i) l.m[i] = new T[l.nCols];

  for(int i = 0; i < l.nRows; i++){
    for(int j = 0; j < l.nCols; j++){
      cin >> l.m[i][j];
    }
  }
  return in;
}


