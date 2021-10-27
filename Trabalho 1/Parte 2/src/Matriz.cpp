#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "../include/Matriz.hpp"

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem) {
    X.nLinhas = ls;
    X.nColunas = cs;

    X.m = new double * [ls];
    for (int i = 0; i < ls; i++) X.m[i] = new double[cs];

    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            X.m[i][j] = elem;
        }
    }

}

void apagaMatriz(Matriz &X) {
    for(int i = 0; i < X.nLinhas; i++) delete[] X.m[i];
    delete[] X.m;
}

Matriz transposta(Matriz &X) {
    
    for(int i = 0; i < X.nLinhas; i++){
        
    }
    return X;
}

Matriz multiplica_por_cte(Matriz &X, double k) {
    for (int i = 0; i < X.nLinhas; i++) {
        for (int j = 0; j < X.nColunas; j++) {
            X.m[i][j] *= k;
        }
    }
    return X;
}

void imprimeMatriz(Matriz &X) {
    for (int i = 0; i < X.nLinhas; i++) {
        for (int j = 0; j < X.nColunas; j++) {
            std::cout << X.m[i][j] << " ";
        }
        std::cout << std::endl;
    }

}