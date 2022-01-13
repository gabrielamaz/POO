#include "Ponto3D.hpp"

class Face : public Ponto3D {
    private:
    Ponto3D A; // inferiro esquerdo
    Ponto3D B; // superior esquedo
    Ponto3D C; // inferiro direito
    Ponto3D D; // superiro direito

    public:
    Face() {
        A.set(0.0, 0.0, 0.0);
        B.set(0.0, 0.0, 0.0);
        C.set(0.0, 0.0, 0.0);
        D.set(0.0, 0.0, 0.0);
    }

    Face(Ponto3D a, Ponto3D b, Ponto3D c, Ponto3D d){
        setAresta_A(a);
        setAresta_B(b);
        setAresta_C(c);
        setAresta_D(d);
    }

    void setAresta_A(Ponto3D a) { A.set(a.get_x(), a.get_y(), a.get_z()); }
    void setAresta_B(Ponto3D b) { B.set(b.get_x(), b.get_y(), b.get_z()); }
    void setAresta_C(Ponto3D c) { C.set(c.get_x(), c.get_y(), c.get_z()); }
    void setAresta_D(Ponto3D d) { D.set(d.get_x(), d.get_y(), d.get_z()); }

    Ponto3D getAresta_a(){ return A; }
    Ponto3D getAresta_b(){ return B; }
    Ponto3D getAresta_c(){ return C; }
    Ponto3D getAresta_d(){ return D; }

    ~Face(){};
};