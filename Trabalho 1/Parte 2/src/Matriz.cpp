#include "../include/Matriz.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem) {
  X.nLinhas = ls;
  X.nColunas = cs;

  X.m = new double *[ls];
  for (int i = 0; i < ls; i++) X.m[i] = new double[cs];

  for (int i = 0; i < ls; i++) {
    for (int j = 0; j < cs; j++) {
      X.m[i][j] = elem;
    }
  }
}

void apagaMatriz(Matriz &X) {
  if (X.m != NULL) {
    for (int i = 0; i < X.nLinhas; i++) delete[] X.m[i];
    delete[] X.m;
    X.m = NULL;
  }
}

Matriz transposta(Matriz &X) {
  Matriz Y;
  Y.nLinhas = X.nColunas;
  Y.nColunas = X.nLinhas;

  Y.m = new double *[Y.nLinhas];

  for (int i = 0; i < Y.nLinhas; i++) Y.m[i] = new double[Y.nColunas];

  for (int i = 0; i < Y.nLinhas; i++) {
    for (int j = 0; j < Y.nColunas; j++) {
      Y.m[i][j] = X.m[j][i];
    }
  }

  return Y;
}

Matriz multiplica_por_cte(Matriz &X, double k) {
  Matriz Y;
  inicializaMatriz(Y, X.nLinhas, X.nColunas, 0);
  
  for (int i = 0; i < X.nLinhas; i++) {
    for (int j = 0; j < X.nColunas; j++) {
      Y.m[i][j] *= X.m[i][j]*k;
    }
  }
  return Y;
}

void imprimeMatriz(Matriz &X) {
  for (int i = 0; i < X.nLinhas; i++) {
    for (int j = 0; j < X.nColunas; j++) {
      std::cout << X.m[i][j] << " ";
    }
    std::cout << std::endl;
  }
}