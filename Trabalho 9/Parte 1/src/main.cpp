#include <iostream>

#include "Professor.hpp"
#include "ProfHorista.hpp"
#include "ProfIntegal.hpp"
#include "Universidade.hpp"

int main() {
    Universidade universidade;
    
    ProfHorista  p1("Professor 1", 35, 100);
    ProfHorista  p2("Professor 2", 30, 80);
    ProfIntegral p3("Professor 3", 6000);

    universidade.addProfessor(&p1);
    universidade.addProfessor(&p2);
    universidade.addProfessor(&p3);

    cout << universidade.totalPago() << endl;
}