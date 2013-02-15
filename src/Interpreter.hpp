#ifndef BF_INTERPRETER
#define BF_INTERPRETER

#include <iostream>

#include "Exception.hpp"
#include "Memory.hpp"

class Interpreter
{
  std::string code;
  int * hash;
  int hashLen;
  Memory memory;
 public:
  Interpreter(std::string code);
  ~Interpreter();
  static std::string interpret(std::string code);
};

#endif
