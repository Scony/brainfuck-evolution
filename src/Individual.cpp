#include "Individual.hpp"

using namespace std;

Individual::Individual(int range_begin, int range_end, string pattern)
{
  this->pattern = pattern;
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
  string output = Interpreter::interpret(code);
  // for(int i = 0; i < output.length(); i++)
  //   cout << "::" << output[i] << "x" << (int)(unsigned char)output[i] << endl;
  rate = 0;
  for(int i = 0; i < pattern.length(); i++)
    if(i < output.length())
      rate += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i]);
    else
      rate += 255;
}

// bool Individual::operator<(const Individual & individual) const
// {
//   return rate > individual.rate;
// }

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

Individual::Box Individual::box()
{
  return Box(this);
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
