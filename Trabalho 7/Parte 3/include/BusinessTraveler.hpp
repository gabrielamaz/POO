#include "Traveler.hpp"
#include "Pager.hpp"

class BusinessTraveler : public Traveler {

  public:
  BusinessTraveler() : Traveler("1"), pager(Pager("1")) {};
  BusinessTraveler(string var) : Traveler(var), pager(Pager(var)) {};
  friend ostream &operator<<(ostream &op, const BusinessTraveler &p);

  private:
    Pager pager;
};

ostream &operator<<(ostream &op, const BusinessTraveler &p) {
  op << endl;
  op << "Traveler: " << p.var << endl;
  op << "Pager: " << p.pager << endl;
  return op;
}


BusinessTraveler &BusinessTraveler::operator=(const BusinessTraveler &p) {
  p.var = p.var;
  p.pager = p.pager;
  return *this;
}