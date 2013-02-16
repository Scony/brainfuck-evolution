#ifndef BF_INTERPRETER
#define BF_INTERPRETER

#define LOOP_CUT 10000

#include <iostream>

// #include "Exception.hpp"
#include "Memory.hpp"

class Interpreter
{
 public:
  static std::string interpret(std::string code);
};

#endif
