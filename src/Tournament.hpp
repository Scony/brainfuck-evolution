#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iostream>
#include <list>

#include "Evolution.hpp"

class Tournament : public Evolution
{
protected:
  int q;			// tournament size
  double pc;			// crossover probability
  double pm;			// mutation probability
  int n;			// elitarity factor
public:
  Tournament(IndividualFactory * factory);
  Tournament(IndividualFactory * factory, int initialSize, int size, int q,
	     double pc, double pm, int n);
  virtual ~Tournament();
  virtual void run();
};

#endif
