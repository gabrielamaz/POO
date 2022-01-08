#include <string>

using namespace std;

class Pager {
 public:
  Pager(string var_) : var(var_){};
  Pager(const Pager &pager_copy) {
    var = pager_copy.var;
  }
  friend ostream &operator<<(ostream &op, const Pager &p);
  Pager &operator=(const Pager &p);
  string getVar() { return var; };
 private:
  string var;
};

ostream &operator<<(ostream &op, const Pager &p) {
  op << endl;
  op << "Pager: " << p.var << endl;
  return op;
}

Pager &Pager::operator=(const Pager &p) {
  var = p.var;
  return *this;
}