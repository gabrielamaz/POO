#include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y) {
  this->x = x;
  this->y = y;
  this->id = getNextId();
}

Ponto2D::~Ponto2D() {
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

void Ponto2D::print() {
  cout << "ID: " << this->id << endl;
  cout << "Coordenada x: " << this->x << endl;
  cout << "Coordenada y: " << this->y << endl;
}

double Ponto2D::distToOrig() {
  double dist;
  dist = pow(0.5, this->x * this->x + this->y * this->y);

  return dist;
}

double Ponto2D::distTo(const Ponto2D &p) {
  double dist;
  dist = pow(0.5, pow(2, this->x - p.x) + pow(2, this->y - p.y));
  return dist;
}

void Ponto2D::sumOf(const Ponto2D &p) {
  this->x += p.x;
  this->y += p.y;
}

void Ponto2D::leitura() {
  
}