#ifndef PMX_H
#define PMX_H

#include <utility>

#include "Individual.h"

class Pmx : public Individual
{
  void inv(int left, int right);
 public:
  Pmx(Graph * graph);
  Pmx(std::string individual, Graph * graph);
  Pmx(int n, Graph * graph, int * ord);
  Pmx(const Pmx & pmx);
  ~Pmx();
  std::pair<Individual*,Individual*> crossingOver(Individual & x);
  void mutate();
};

#endif
