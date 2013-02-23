#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"
#include "IndividualFactory.hpp"

class Evolution
{
protected:
  IndividualFactory * factory;

  std::list<Individual::Box> population;
  int initialSize;
  int size;

  void fillPopulation(int count);
public:
  Evolution(IndividualFactory * factory);
  Evolution(IndividualFactory * factory, int initialSize, int size);
  virtual ~Evolution();
  virtual void run();
};

#endif
