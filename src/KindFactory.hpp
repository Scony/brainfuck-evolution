#ifndef KIND_FACTORY_HPP
#define KIND_FACTORY_HPP

#include <iostream>

#include "IndividualFactory.hpp"
#include "Individual.hpp"
// #include "Pmx.hpp"

class KindFactory : public IndividualFactory
{
  int kind;
  int range_begin;
  int range_end;
  std::string pattern;
public:
  KindFactory(int kind, int range_begin, int range_end, std::string pattern);
  ~KindFactory();
  Individual * makeIndividual();
};

#endif
