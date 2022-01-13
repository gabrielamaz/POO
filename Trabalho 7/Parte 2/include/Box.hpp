#include "Face.hpp"

Face nova_face(){
    int x, y, z;

    cout << "Digite o valor do ponto inferiro esquerdo: " << endl;
    cin >> x >> y >> z;
    Ponto3D inf_esquerdo;
    inf_esquerdo.set(x, y, z);

    cout << "Digite o valor do ponto superiro esquerdo: " << endl;
    cin >> x >> y >> z;
    Ponto3D sup_esquerdo;
    sup_esquerdo.set(x, y, z);

    cout << "Digite o valor do ponto inferiro direito: " << endl;
    cin >> x >> y >> z;
    Ponto3D inf_direito;
    inf_direito.set(x, y, z);

    cout << "Digite o valor do ponto superior direito: " << endl;
    cin >> x >> y >> z;
    Ponto3D sup_direito;
    sup_direito.set(x, y, z);
    
    Face *A = new Face(inf_esquerdo, sup_esquerdo, inf_direito, sup_direito);

    return *A;
}

class Box : public Face {
    private:
        Face A; // esquerda
        Face B; // frontal
        Face C; // direita
        Face D; // traseira
        Face E; // superior
        Face F; // inferiro

    public:
        Box();

        //bool conferir();

        Face get_face_A() { return A; }
        Face get_face_B() { return B; }
        Face get_face_C() { return C; }
        Face get_face_D() { return D; }
        Face get_face_E() { return E; }
        Face get_face_F() { return F; }
};

Box::Box(){
    cout << "serao criadas 6 faces"  << endl;
    cout << "1 face, lado esquesdo" << endl;
    A = nova_face();

    cout << "2 face, lado frontal" << endl;
    B = nova_face();

    cout << "3 face, lado direito" << endl;
    C = nova_face();

    cout << "4 face, lado traseiro" << endl;
    D = nova_face();

    cout << "5 face, lado superior" << endl;
    E = nova_face();

    cout << "6 face, lado inferior" << endl;
    F = nova_face();
}