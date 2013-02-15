#ifndef INDIVIDUAL_FACTORY_HPP
#define INDIVIDUAL_FACTORY_HPP

#include "Individual.hpp"

class IndividualFactory
{
public:
  IndividualFactory();
  virtual ~IndividualFactory();
  virtual Individual * makeIndividual() = 0;
};

#endif
