#include "AlgorithmFactory.hpp"

AlgorithmFactory::AlgorithmFactory(int kind, IndividualFactory * factory, int initialSize, int size,
				   int q, double pc, double pm, int n)
{
  this->kind = kind;

  this->factory = factory;
  this->initialSize = initialSize;
  this->size = size;
  this->q = q;
  this->pc = pc;
  this->pm = pm;
  this->n = n;
}

AlgorithmFactory::~AlgorithmFactory()
{
}

Evolution * AlgorithmFactory::makeAlgorithm()
{
  switch(kind)
    {
    case 1:
      return new Roulette(factory,initialSize,size,pc,pm,n);
      break;
    case 2:
      return new Tournament(factory,initialSize,size,q,pc,pm,n);
      break;
    default:
      return new Evolution(factory,initialSize,size);
    }
}
