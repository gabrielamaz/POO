#include "Tempo.hpp"

Tempo::Tempo(int dia, int hora, int min, int seg) {
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;

  this->verificaConsistencia();
}



void Tempo::verificaConsistencia() {}

void Tempo::verificaSegundos() {
    if (this->seg >= 60){
        this->seg -= 60;
        this->incrementaMinuto();
    }
    verificaMinutos();
}

Tempo::~Tempo() {}
