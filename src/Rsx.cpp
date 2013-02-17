#include <stack>

#include "Rsx.hpp"

using namespace std;

Rsx::Rsx(int range_begin, int range_end, std::string pattern)
: Individual(range_begin,range_end,pattern)
{
}

Rsx::Rsx(const Individual & origin) : Individual(origin)
{
}

Rsx::~Rsx()
{
}

void Rsx::rangeRand(int left, int right)
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

std::list<Individual::Box> Rsx::crossingOver(Individual & other)
{
  Rsx * a = new Rsx(*this);
  Rsx * b = new Rsx(other);

  if(a->code.length() < b->code.length())
    {
      stack<int> hill;

      hill.push(-1);
      hill.push(Utils::randEx(1,a->code.length()-1));
      int offset = Utils::randEx(0,a->code.length()); //prawy koniec moze byc zludny
      while(hill.top() + offset < a->code.length() - 1)
	{
	  hill.push(hill.top() + offset);
	  offset = Utils::randEx(1,a->code.length());
	}
      hill.push(a->code.length()-1);

      while(hill.size() > 1)
	{
	  int end = hill.top();
	  hill.pop();
	  int begin = hill.top() + 1;
	  int width = end - begin + 1;

	  int it = Utils::randEx(0,b->code.length()-width);
	  for(int i = begin; i <= end; i++)
	    Utils::swapc(a->code[i],b->code[it++]);
	}
    }
  else
    {
      stack<int> hill;

      hill.push(-1);
      hill.push(Utils::randEx(1,b->code.length()-1));
      int offset = Utils::randEx(0,b->code.length()); //prawy koniec moze byc zludny
      while(hill.top() + offset < b->code.length() - 1)
	{
	  hill.push(hill.top() + offset);
	  offset = Utils::randEx(1,b->code.length());
	}
      hill.push(b->code.length()-1);

      while(hill.size() > 1)
	{
	  int end = hill.top();
	  hill.pop();
	  int begin = hill.top() + 1;
	  int width = end - begin + 1;

	  int it = Utils::randEx(0,a->code.length()-width);
	  for(int i = begin; i <= end; i++)
	    Utils::swapc(b->code[i],a->code[it++]);
	}
    }

  a->eval();
  b->eval();

  list<Box> ret;
  ret.push_back(a->box());
  ret.push_back(b->box());

  return ret;
}

void Rsx::mutate()
{
  int a = Utils::randEx(0,code.length()-1);
  int b = Utils::randEx(0,code.length()-1);

  if(a < b)
    rangeRand(a,b);
  else
    rangeRand(b,a);

  eval();
}
