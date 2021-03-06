#include "KindFactory.hpp"

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

Individual * KindFactory::makeIndividual()
{
  switch(kind)
    {
    case 1:
      return new Pmx(range_begin,range_end,pattern);
    case 2:
      return new Sx(range_begin,range_end,pattern);
    case 3:
      return new Rsx(range_begin,range_end,pattern);
    default:
      return new Eru(range_begin,range_end,pattern);
    }
}
