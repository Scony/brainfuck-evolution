#ifndef PMX_HPP
#define PMX_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"

class Pmx : public Individual
{
 public:
  Pmx(int range_begin, int range_end, std::string pattern);
  Pmx(const Individual & origin);
  virtual ~Pmx();
  virtual std::list<Box> crossingOver(Individual & other);
  virtual void mutate(double pm);
  virtual Individual * clone();
};

#endif
