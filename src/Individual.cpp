#include "Individual.hpp"

using namespace std;

Individual::Individual(int range_begin, int range_end, string pattern)
{
  this->pattern = pattern;
  range_max = range_end;
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
  // // version 1
  // // 
  // string output = Interpreter::interpret(code);
  // rate = 0;
  // for(int i = 0; i < pattern.length(); i++)
  //   if(i < output.length())
  //     rate += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i]);
  //   else
  //     rate += 255;

  // // version 2
  // // 
  // string output = Interpreter::interpret(code);
  // output = output.substr(0,pattern.length()*5);
  // rate = 0;

  // long long min = 99999999;

  // if(!output.length())
  //   min = pattern.length() * 255;
  // else
  //   for(int j = 0; j < output.length(); j++)
  //     {
  // 	int local = 0;
  // 	for(int i = 0; i < pattern.length(); i++)
  // 	  if(i + j < output.length())
  // 	    local += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i+j]);
  // 	  else
  // 	    local += 255;
  // 	if(local < min)
  // 	  min = local;
  //     }
  
  // rate = min;

  // // version 3
  // // 
  // string output = Interpreter::interpret(code);
  // output = output.substr(0,pattern.length()*5);
  // rate = 0;

  // long long min = 99999999;
  // int minj = 99999999;

  // if(!output.length())
  //   min = pattern.length() * 255 * output.length();
  // else
  //   for(int j = 0; j < output.length(); j++)
  //     {
  // 	int local = 0;
  // 	for(int i = 0; i < pattern.length(); i++)
  // 	  if(i + j < output.length())
  // 	    local += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i+j]);
  // 	  else
  // 	    local += 255;
  // 	if(local < min)
  // 	  {
  // 	    min = local;
  // 	    minj = j;
  // 	  }
  //     }
  
  // rate = min * output.length() + minj;

  // version 5
  // 
  string output = Interpreter::interpret(code);
  rate = 0;
  for(int i = 0; i < pattern.length(); i++)
    if(i < output.length())
      rate += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i]) * range_max;
    else
      rate += 255 * range_max;

  rate += code.length();
}

bool Individual::operator<(const Individual & individual) const
{
  return rate > individual.rate;
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
