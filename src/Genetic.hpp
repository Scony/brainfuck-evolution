#ifndef GENETIC_HPP
#define GENETIC_HPP

#include <iostream>
#include <list>

#include "Evolution.hpp"

class Genetic : public Evolution
{
protected:
  int q;			// tournament size
  double pc;			// crossover probability
  double pm;			// mutation probability
  int n;			// elitarity factor
public:
  Genetic(IndividualFactory * factory);
  Genetic(IndividualFactory * factory, int initialSize, int size, int q,
	  double pc, double pm, int n);
  virtual ~Genetic();
  virtual void run();
};

#endif
