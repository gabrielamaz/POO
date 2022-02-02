#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>

using namespace std;

class Professor {
 private:
  string nome;

 public:
  Professor(string n) {nome = n;};
  string getName() const {return nome;};
  virtual double getSalario() = 0;
  virtual ~Professor();
};

#endif