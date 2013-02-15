#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"
#include "IndividualFactory.hpp"

class Evolution
{
  IndividualFactory * factory;

  std::list<Individual::Box> population;
  int startPopulation;
  int population;
  int mutations;

  void makePopulation();
 public:
  Evolution(IndividualFactory * factory);
  ~Evolution();
  void run();
};

#endif
