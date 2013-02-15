#include "Individual.hpp"

using namespace std;

Individual::Individual(string pattern) : this->pattern = pattern
{
  //
}

Individual::~Individual()
{
}

void Individual::shuffle()
{
  for(int i = 0; i < n; i++)
    {
      int j = randEx(1,n-1);
      Utils::swapc(ord[i],ord[j]);
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
