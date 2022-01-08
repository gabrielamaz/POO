#include <string>

using namespace std;

class Traveler {
 public:
  Traveler(string var_) : var(var_){};
  string getVar() { return var; };

 protected:
  string var;
};