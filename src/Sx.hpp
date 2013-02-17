#ifndef SX_HPP
#define SX_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"

class Sx : public Individual
{
  void rangeRand(int left, int right);
 public:
  Sx(int range_begin, int range_end, std::string pattern);
  Sx(const Individual & origin);
  ~Sx();
  std::list<Box> crossingOver(Individual & other);
  void mutate();
};

#endif
