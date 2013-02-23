#include "Eru.hpp"

using namespace std;

Eru::Eru(int range_begin, int range_end, std::string pattern)
: Individual(range_begin,range_end,pattern)
{
}

Eru::Eru(const Individual & origin) : Individual(origin)
{
}

Eru::~Eru()
{
}

std::list<Individual::Box> Eru::crossingOver(Individual & other)
{
  Eru * a = new Eru(*this);
  Eru * b = new Eru(other);

  int diff = Utils::abs(a->code.length()-b->code.length());

  if(a->code.length() > b->code.length())
    {
      for(int i = 0, j = 0; i < b->code.length(); i++, j++)
	if(Utils::randd() <= 0.5)
	  {
	    int offset = Utils::randr(0,diff);
	    j += offset;
	    diff -= offset;
	    Utils::swapc(a->code[j],b->code[i]);
	  }
    }
  else
    {
      for(int i = 0, j = 0; i < a->code.length(); i++, j++)
	if(Utils::randd() <= 0.5)
	  {
	    int offset = Utils::randr(0,diff);
	    j += offset;
	    diff -= offset;
	    Utils::swapc(a->code[i],b->code[j]);
	  }
    }

  a->eval();
  b->eval();

  list<Box> ret;
  ret.push_back(a->box());
  ret.push_back(b->box());

  return ret;
}

void Eru::mutate(double pm)
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
      }

  eval();
}

Individual * Eru::clone()
{
  return new Eru(*this);
}
