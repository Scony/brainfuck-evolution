#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <iostream>
#include <list>

#include "Evolution.hpp"

class Roulette : public Evolution
{
protected:
  double pc;			// crossover probability
  double pm;			// mutation probability
  int n;			// elitarity factor
public:
  Roulette(IndividualFactory * factory);
  Roulette(IndividualFactory * factory, int initialSize, int size,
	  double pc, double pm, int n);
  virtual ~Roulette();
  virtual void run();
};

#endif
