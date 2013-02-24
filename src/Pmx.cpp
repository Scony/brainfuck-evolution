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

list<Individual::Box> Pmx::crossingOver(Individual & other)
{
  int width = Utils::randr(1,Utils::min(code.length(),other.toString().length()));
  int offsetA = Utils::randr(0,code.length()-width);
  int offsetB = Utils::randr(0,other.toString().length()-width);

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

void Pmx::mutate(double pm)
{
  for(int i = 0; i < code.length(); i++)
    if(Utils::randd() <= pm)
      {
	int op = Utils::randr(0,7);
	switch(op)
	  {
	  case 0:
	    code[i] = '+';
	    break;
	  case 1:
	    code[i] = '-';
	    break;
	  case 2:
	    code[i] = '>';
	    break;
	  case 3:
	    code[i] = '<';
	    break;
	  case 4:
	    code[i] = '[';
	    break;
	  case 5:
	    code[i] = ']';
	    break;
	  case 6:
	    code[i] = ',';
	    break;
	  case 7:
	    code[i] = '.';
	  }

	eval();
      }
}

Individual * Pmx::clone()
{
  return new Pmx(*this);
}
