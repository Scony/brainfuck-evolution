#ifndef PMX_HPP
#define PMX_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"

class Pmx : public Individual
{
  void rangeRand(int left, int right);
  void inv(int left, int right);
 public:
  Pmx(int range_begin, int range_end, std::string pattern);
  Pmx(const Individual & origin);
  ~Pmx();
  std::list<Box> crossingOver(Individual & other);
  void mutate();
};

#endif
