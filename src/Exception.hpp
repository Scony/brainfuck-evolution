#ifndef BF_EXCEPTION
#define BF_EXCEPTION

#include <iostream>

class Exception
{
  std::string message;
 public:
  Exception(std::string message);
  Exception();
  std::string toString();
};

#endif
