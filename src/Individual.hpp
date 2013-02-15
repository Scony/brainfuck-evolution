#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <iostream>
#include <list>

#include "Utils.hpp"

class Individual
{
protected:
  std::string code;
  std::string & pattern;
  long long rate;

  void shuffle();
  void eval();
public:
  struct Box
  {
    Individual * individual;
    Box(Individual * individual);
    ~Box();
    bool operator<(const Box & box) const;
    void remove();
  };

  Individual(int range_begin, int range_end, std::string pattern);
  virtual ~Individual();
  bool operator<(const Individual & individual) const;
  virtual std::list<Box> crossingOver(Individual & other);
  virtual void mutate();
  long long getRate();
  Box box();
  std::string toString();
};

#endif
