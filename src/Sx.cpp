#include "Sx.hpp"

using namespace std;

Sx::Sx(int range_begin, int range_end, std::string pattern)
: Pmx(range_begin,range_end,pattern)
{
}

Sx::Sx(const Individual & origin) : Pmx(origin)
{
}

Sx::~Sx()
{
}

list<Individual::Box> Sx::crossingOver(Individual & other)
{
  Sx * a = new Sx(*this);
  Sx * b = new Sx(other);

  int k = min(toString().length(),other.toString().length()) / 2;

  while(k--)
    {
      int aIt = Utils::randr(0,toString().length()-1);
      int bIt = Utils::randr(0,other.toString().length()-1);
      Utils::swapc(a->code[aIt],b->code[bIt]);
    }

  a->eval();
  b->eval();

  list<Box> ret;
  ret.push_back(a->box());
  ret.push_back(b->box());

  return ret;
}

Individual * Sx::clone()
{
  return new Sx(*this);
}
