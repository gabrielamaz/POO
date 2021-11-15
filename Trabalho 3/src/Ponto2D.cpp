#include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y) {
  this->x = x;
  this->y = y;
  this->id = getNextId();
}

Ponto2D::~Ponto2D(){
  vector<int>::iterator it;
  it = find(this->idList.begin(), this->idList.end(), id);
  this->idList.erase(it);
}

int Ponto2D::getNextId() {
  int id;
  uniform_int_distribution<> d(0, 1000);
  mt19937 gen;
  id = d(gen);
  vector<int>::iterator it;
  it = find(this->idList.begin(), this->idList.end(), id);
  if (it != this->idList.end()) {
    return id;
  } else {
    return this->getNextId();
  }
}