#ifndef ALGORITHM_FACTORY_HPP
#define ALGORITHM_FACTORY_HPP

#include "Evolution.hpp"
#include "Roulette.hpp"
#include "Tournament.hpp"

class AlgorithmFactory
{
  int kind;

  IndividualFactory * factory;
  int initialSize;
  int size;
  int q;
  double pc;
  double pm;
  int n;
public:
  AlgorithmFactory(int kind, IndividualFactory * factory, int initialSize, int size,
		   int q, double pc, double pm, int n);
  ~AlgorithmFactory();
  Evolution * makeAlgorithm();
};

#endif
