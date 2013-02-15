#include "IndividualFactory.hpp"

using namespace std;

KindFactory::KindFactory(int kind, int range_begin, int range_end, string pattern)
{
  this->kind = kind;
  this->range_begin = range_begin;
  this->range_end = range_end;
  this->pattern = pattern;
}

KindFactory::~KindFactory()
{
}

KindFactory::makeIndividual()
{
  switch(kind)
    {
    default:
      return new Individual(range_begin,range_end,pattern);
    }
}
