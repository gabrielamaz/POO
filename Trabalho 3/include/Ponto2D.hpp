#ifndef PONTO2D_HPP
#define PONTO2D_HPP

#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Ponto2D {
 private:
  int id;
  double x, y;
  static vector<int> idList;
  int getNextId();

 public:
  Ponto2D(double = 0.0, double = 0.0);
  ~Ponto2D();
  double getX() {return this->x;}
  double getY() {return this->y;}
  int getID() { return this->id;}
  void print();
  double distToOrig();
  double distTo(const Ponto2D &);
  void sumOf(const Ponto2D &);
  void leitura();
};

#endif