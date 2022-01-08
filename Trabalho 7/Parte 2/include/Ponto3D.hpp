#include "Ponto2D.hpp"

class Ponto3D : public Ponto2D {
 public:
  Ponto3D(double xx = 0, double yy = 0, double zz = 0)
      : Ponto2D(xx, yy), z(zz){};
  friend ostream &operator<<(ostream &op, const Ponto3D &p);
  Ponto3D &operator=(const Ponto2D &p);
  void set(double nx = 0, double ny = 0, double nz = 0) {
    x = nx;
    y = ny;
    z = nz;
  }
  double get_x(void) { return x; }
  double get_y(void) { return y; }
  double get_z(void) { return z; }

 private:
  double z;
};

ostream &operator<<(ostream &op, const Ponto3D &p) {
  op << endl;
  op << "x = " << p.x << endl;
  op << "y = " << p.y << endl;
  op << "z = " << p.z << endl;

  return op;
}

Ponto3D &Ponto3D::operator=(const Ponto2D &p) {
  x = p.x;
  y = p.y;
  return *this;
}
