#include <iostream>
#include "Tempo.hpp"

using namespace std;

Tempo::Tempo(int dia, int hora, int min, int seg) {
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;

  this->verificaConsistencia();
}

void Tempo::verificaSegundos() {
  if (this->seg >= 60){
      this->seg -= 60;
      this->incrementaMinuto();
  }
  verificaMinutos();
}

void Tempo::verificaMinutos() {
  if (this->min >= 60){
      this->min -= 60;
      this->incrementaHora();
  }
  verificaHoras();
}

void Tempo::verificaHoras() {
  if (this->hora >= 24){
      this->hora -= 24;
      this->incrementaDia();
  }
}

Tempo Tempo::somaTempo(Tempo t1){
  dia  += t1.getDia();
  hora += t1.getHora();
  min  += t1.getMin();
  seg  += t1.getSeg();

  verificaConsistencia();
}

void Tempo::leitura(){  
  cout << "Digite o dia: ";
  cin >> dia;
  cout << "Digite a hora: ";
  cin >> hora;
  cout << "Digite os minutos: ";
  cin >> min;
  cout << "Digite os segundos: ";
  cin >> seg;

  verificaConsistencia();
}

void Tempo::escrita(){
  verificaConsistencia();

  cout << dia << ":" << hora << ":" << min << ":" << seg << endl;
}