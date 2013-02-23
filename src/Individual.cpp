#include "Individual.hpp"

using namespace std;

Individual::Individual(int range_begin, int range_end, string pattern)
{
  this->pattern = pattern;
  range_max = range_end;
  code = "";
  fitness = 0;

  int length = Utils::randr(range_begin,range_end);
  for(int i = 0; i < length; i++)
    {
      int op = Utils::randr(0,7);
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

Individual::Individual(string code, string pattern)
{
  this->pattern = pattern;
  this->code = code;
  range_max = -1;
  fitness = 0;

  eval();
}

Individual::~Individual()
{
}

void Individual::shuffle()
{
  for(int i = 0; i < code.length(); i++)
    {
      int j = Utils::randr(1,code.length()-1);
      Utils::swapc(code[i],code[j]);
    }
}

void Individual::eval()
{
  switch(1)
    {
    case 1:			// simple ascii codes difference
      {
	string output = Interpreter::interpret(code);
	fitness = 0;
	for(int i = 0; i < pattern.length(); i++)
	  if(i < output.length())
	    fitness += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i]);
	  else
	    fitness += 255;
      }
      break;
    case 2:			// floating pattern
      {
	string output = Interpreter::interpret(code);
	output = output.substr(0,pattern.length()*5);
	fitness = 0;

	long long min = 99999999;

	if(!output.length())
	  min = pattern.length() * 255;
	else
	  for(int j = 0; j < output.length(); j++)
	    {
	      int local = 0;
	      for(int i = 0; i < pattern.length(); i++)
		if(i + j < output.length())
		  local += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i+j]);
		else
		  local += 255;
	      if(local < min)
		min = local;
	    }
  
	fitness = min;
      }
      break;
    case 3:			// floating pattern + code length
      {
	string output = Interpreter::interpret(code);
	output = output.substr(0,pattern.length()*5);
	fitness = 0;

	long long min = 99999999;
	int minj = 99999999;

	if(!output.length())
	  min = pattern.length() * 255 * output.length();
	else
	  for(int j = 0; j < output.length(); j++)
	    {
	      int local = 0;
	      for(int i = 0; i < pattern.length(); i++)
		if(i + j < output.length())
		  local += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i+j]);
		else
		  local += 255;
	      if(local < min)
		{
		  min = local;
		  minj = j;
		}
	    }
  
	fitness = min * output.length() + minj;
      }
      break;
    default:			// simple ascii difference + code length
      {
	string output = Interpreter::interpret(code);
	fitness = 0;
	for(int i = 0; i < pattern.length(); i++)
	  if(i < output.length())
	    fitness += abs((int)(unsigned char)pattern[i] - (int)(unsigned char)output[i]) * range_max;
	  else
	    fitness += 255 * range_max;

	fitness += code.length();
      }
      break;
    }
}

bool Individual::operator<(const Individual & individual) const
{
  return fitness > individual.fitness;
}

list<Individual::Box> Individual::crossingOver(Individual & other)
{
  list<Individual::Box> ret;
  ret.push_back(new Individual(*this));

  return ret;
}

void Individual::mutate(double pm)
{
}

Individual * Individual::clone()
{
  return new Individual(*this);
}

long long Individual::getFitness()
{
  return fitness;
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
  return individual->getFitness() < box.individual->getFitness();
}

void Individual::Box::remove()
{
  delete individual;
}
