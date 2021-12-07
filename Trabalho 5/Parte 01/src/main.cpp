#include <iostream>

class Ponto2D {
  int x, y;

 public:
  Ponto2D(int xx = 0, int yy = 0) : x(xx), y(yy){};
  Ponto2D& operator--();
  Ponto2D operator+(const Ponto2D&) const;
  ~Ponto2D(){};
};

Ponto2D& Ponto2D::operator--() {
  this->x--;
  this->y--;
}

Ponto2D Ponto2D::operator+(const Ponto2D& b) const {
  Ponto2D c;
  c.x = this->x + b.x;
  c.y = this->y + b.y;
  return c;
}

int main() {
  Ponto2D a(1, 4), b(3, 2), c;
  c = a + b;  // soma as coordenadas dos pontos a e b
  --c;        // decrementa em uma unidade as coordenadas de c
}