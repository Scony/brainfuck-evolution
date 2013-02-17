#ifndef RSX_HPP
#define RSX_HPP

#include <iostream>
#include <list>

#include "Individual.hpp"

class Rsx : public Individual
{
  void rangeRand(int left, int right);
 public:
  Rsx(int range_begin, int range_end, std::string pattern);
  Rsx(const Individual & origin);
  ~Rsx();
  std::list<Box> crossingOver(Individual & other);
  void mutate();
};

#endif
