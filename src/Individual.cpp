#include "Individual.hpp"

using namespace std;

Individual::Individual(string pattern) : pattern(pattern)
{
  //
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
  //interpret
  //out vs pattern
}

bool Individual::operator<(const Individual & individual) const
{
  return rate < individual.rate;
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
