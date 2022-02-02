#include "Universidade.hpp"

void Universidade::addProfessor(Professor const &prof) {
  this->professores.push_back(prof);
}