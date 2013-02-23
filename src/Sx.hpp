#ifndef SX_HPP
#define SX_HPP

#include <iostream>
#include <list>

#include "Pmx.hpp"

class Sx : public Pmx
{
 public:
  Sx(int range_begin, int range_end, std::string pattern);
  Sx(const Individual & origin);
  ~Sx();
  std::list<Box> crossingOver(Individual & other);
  Individual * clone();
};

#endif
