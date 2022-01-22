#ifndef CONHECIDO_HPP
#define CONHECIDO_HPP

#include <string>

#include "Pessoa.hpp"

using namespace std;
class Conhecido : public Pessoa {
  public:
    Conhecido() : email("indefinido"), Pessoa() {};

  private:
    string email;
};

#endif