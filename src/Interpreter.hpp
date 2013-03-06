#ifndef BF_INTERPRETER
#define BF_INTERPRETER

#define LOOP_CUT 1000

#include <iostream>

#include "Memory.hpp"

class Interpreter
{
 public:
  static std::string interpret(std::string code);
};

#endif
