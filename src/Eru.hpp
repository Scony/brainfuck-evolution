#ifndef ERU_HPP
#define ERU_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"

class Eru : public Individual
{
 public:
  Eru(int range_begin, int range_end, std::string pattern);
  Eru(const Individual & origin);
  ~Eru();
  std::list<Box> crossingOver(Individual & other);
  void mutate(double pm);
  Individual * clone();
};

#endif
