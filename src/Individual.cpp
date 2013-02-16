#include "Individual.hpp"

using namespace std;

Individual::Individual(int range_begin, int range_end, string pattern) : pattern(pattern)
{
  code = "";
  rate = 0;

  int length = Utils::randEx(range_begin,range_end);
  for(int i = 0; i < length; i++)
    {
      int op = Utils::randEx(0,7);
      switch(op)
	{
	case 0:
	  code += "+";
	  break;
	case 1:
	  code += "-";
	  break;
	case 2:
	  code += ">";
	  break;
	case 3:
	  code += "<";
	  break;
	case 4:
	  code += "[";
	  break;
	case 5:
	  code += "]";
	  break;
	case 6:
	  code += ",";
	  break;
	case 7:
	  code += ".";
	  break;
	}
    }
  // shuffle();
  eval();
}

Individual::~Individual()
{
}

void Individual::shuffle()
{
  for(int i = 0; i < code.length(); i++)
    {
      int j = Utils::randEx(1,code.length()-1);
      Utils::swapc(code[i],code[j]);
    }
}

void Individual::eval()
{
  // cout << "ev::" << Interpreter::interpret(code) << endl;
  string tmp = Interpreter::interpret(code);
  for(int i = 0; i < tmp.length(); i++)
    cout << "::" << tmp[i] << "x" << (int)(unsigned char)tmp[i] << endl;
  //out vs pattern
}

bool Individual::operator<(const Individual & individual) const
{
  return rate < individual.rate;
}

list<Individual::Box> Individual::crossingOver(Individual & other)
{
  list<Individual::Box> ret;
  ret.push_back(new Individual(*this));

  return ret;
}

void Individual::mutate()
{
}

long long Individual::getRate()
{
  return rate;
}

string Individual::toString()
{
  return code;
}

Individual::Box::Box(Individual * individual)
{
  this->individual = individual;
}

Individual::Box::~Box()
{
}

bool Individual::Box::operator<(const Box & box) const
{
  return individual->getRate() < box.individual->getRate();
}

void Individual::Box::remove()
{
  delete individual;
}
