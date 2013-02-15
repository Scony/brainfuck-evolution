#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <utility>

#include "Graph.h"
#include "Utils.h"

class Individual
{
 protected:
  int n;
  int * ord;
  long long rate;
  Graph * graph;
  int randEx(int range_min, int range_max);
  void swap(int & a, int & b);
  void eval();
 public:
  Individual(Graph * graph);
  Individual(std::string individual, Graph * graph);
  Individual(int n, Graph * graph, int * ord);
  Individual(const Individual & individual);
  virtual ~Individual();
  bool operator<(const Individual & individual) const;
  virtual std::pair<Individual*,Individual*> crossingOver(Individual & other);
  virtual void mutate();
  long long getRate();
  int getOrd(int index);
  std::string toString();
  void shuffle();
};

#endif
