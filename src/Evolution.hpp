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
  int populationCut;
  int mutations;
  int injections;

  void fillPopulation(int count);
 public:
  Evolution(IndividualFactory * factory);
  Evolution(IndividualFactory * factory, int startPopulation,
	    int populationCut, int mutations, int injections);
  ~Evolution();
  void run();
};

#endif
