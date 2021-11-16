#include "Ponto2D.hpp"

set<int> Ponto2D::idSet;

Ponto2D::Ponto2D(double x, double y) {
  this->x = x;
  this->y = y;
  this->id = getNextId();
}

Ponto2D::~Ponto2D() {
  std::set<int>::iterator it;
  it = idSet.find(id);
  this->idSet.erase(it, idSet.end());
}

int Ponto2D::getNextId() {
  int id;
  id = rand() % 1000;
  pair<std::set<int>::iterator,bool> ret;
  ret = this->idSet.insert(id);
  if (ret.second==false){
    return this->getNextId();
  } else {
    return id;
  }
}

void Ponto2D::print() {
  cout << "ID: " << this->id << endl;
  cout << "Coordenada x: " << this->x << endl;
  cout << "Coordenada y: " << this->y << endl;
}

double Ponto2D::distToOrig() {
  double dist;
  dist = pow(this->x * this->x + this->y * this->y, 0.5);

  return dist;
}

double Ponto2D::distTo(const Ponto2D &p) {
  double dist;
  dist = pow(pow(this->x - p.x, 2) + pow(this->y - p.y, 2), 0.5);
  return dist;
}

void Ponto2D::sumOf(const Ponto2D &p) {
  this->x += p.x;
  this->y += p.y;
}

void Ponto2D::leitura() {
  cout << "Digite os dados pedidos." << endl;
  cout << "Coordenada em x: " << endl;
  cin >> this->x;
  cout << "Coordenada em y: " << endl;
  cin >> this->y;
}

void Ponto2D::printIds() {
  for (int id : idSet)
    {
        std::cout << id << ' ';
    }
    cout << endl;
}