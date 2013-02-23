#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include <iostream>
#include <list>

#include "Utils.hpp"
#include "Interpreter.hpp"

class Individual
{
protected:
  std::string code;
  std::string pattern;
  long long fitness;
  int range_max;

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
  virtual void mutate(double pm);
  virtual Individual * clone();
  long long getFitness();
  Box box();
  std::string toString();
};

#endif
