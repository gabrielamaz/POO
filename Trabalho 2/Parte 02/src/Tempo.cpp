#include "Tempo.hpp"

Tempo::Tempo(int dia, int hora, int min, int seg) {
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;

    this->verificaConsistencia();
}

void verificaConsistencia() {

}

Tempo::~Tempo() {}
