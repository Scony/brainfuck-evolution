#ifndef INDIVIDUAL_FACTORY_HPP
#define INDIVIDUAL_FACTORY_HPP

#include "Individual.hpp"
#include "Pmx.hpp"

class IndividualFactory
{
public:
  IndividualFactory();
  virtual ~IndividualFactory();
  virtual Individual * makeIndividual() = 0;
};

#endif
