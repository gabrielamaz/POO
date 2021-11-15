#ifndef PONTO2D_HPP
#define PONTO2D_HPP

#include <algorithm>
#include <vector>
#include <random>

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
  void print();
  double distToOrig();
  double distTo(const Ponto2D &);
  double sumOf(const Ponto2D &);
};

#endif