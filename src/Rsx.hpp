#ifndef RSX_HPP
#define RSX_HPP

#include <iostream>
#include <list>

#include "Pmx.hpp"

class Rsx : public Pmx
{
 public:
  Rsx(int range_begin, int range_end, std::string pattern);
  Rsx(const Individual & origin);
  ~Rsx();
  std::list<Box> crossingOver(Individual & other);
  Individual * clone();
};

#endif
