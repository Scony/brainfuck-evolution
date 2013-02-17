#include "Sx.hpp"

using namespace std;

Sx::Sx(int range_begin, int range_end, std::string pattern)
: Individual(range_begin,range_end,pattern)
{
}

Sx::Sx(const Individual & origin) : Individual(origin)
{
}

Sx::~Sx()
{
}

void Sx::rangeRand(int left, int right)
{
  while(left <= right)
    {
      int op = Utils::randEx(0,7);
      switch(op)
	{
	case 0:
	  code[left++] = '+';
	  break;
	case 1:
	  code[left++] = '-';
	  break;
	case 2:
	  code[left++] = '>';
	  break;
	case 3:
	  code[left++] = '<';
	  break;
	case 4:
	  code[left++] = '[';
	  break;
	case 5:
	  code[left++] = ']';
	  break;
	case 6:
	  code[left++] = ',';
	  break;
	case 7:
	  code[left++] = '.';
	  break;
	}
    }
}

std::list<Individual::Box> Sx::crossingOver(Individual & other)
{
  Sx * a = new Sx(*this);
  Sx * b = new Sx(other);

  int k = min(toString().length(),other.toString().length()) / 2;

  while(k--)
    {
      int aIt = Utils::randEx(0,toString().length()-1);
      int bIt = Utils::randEx(0,other.toString().length()-1);
      Utils::swapc(a->code[aIt],b->code[bIt]);
    }

  a->eval();
  b->eval();

  list<Box> ret;
  ret.push_back(a->box());
  ret.push_back(b->box());

  return ret;
}

void Sx::mutate()
{
  int a = Utils::randEx(0,code.length()-1);
  int b = Utils::randEx(0,code.length()-1);

  if(a < b)
    rangeRand(a,b);
  else
    rangeRand(b,a);

  eval();
}
