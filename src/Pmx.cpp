#include "Pmx.hpp"

using namespace std;

Pmx::Pmx(int range_begin, int range_end, std::string pattern)
: Individual(range_begin,range_end,pattern)
{
}

Pmx::Pmx(const Individual & origin) : Individual(origin)
{
}

Pmx::~Pmx()
{
}

void Pmx::rangeRand(int left, int right)
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

std::list<Individual::Box> Pmx::crossingOver(Individual & other)
{
  int width = Utils::randEx(1,Utils::min(code.length(),other.toString().length()));
  int offsetA = Utils::randEx(0,code.length()-width);
  int offsetB = Utils::randEx(0,other.toString().length()-width);

  Pmx * a = new Pmx(*this);
  Pmx * b = new Pmx(other);

  for(int i = 0; i < width; i++)
    Utils::swapc(a->code[offsetA++],b->code[offsetB++]);

  a->eval();
  b->eval();

  list<Box> ret;
  ret.push_back(a->box());
  ret.push_back(b->box());

  return ret;
}

void Pmx::mutate()
{
  int a = Utils::randEx(0,code.length()-1);
  int b = Utils::randEx(0,code.length()-1);

  if(a < b)
    rangeRand(a,b);
  else
    rangeRand(b,a);

  eval();
}
