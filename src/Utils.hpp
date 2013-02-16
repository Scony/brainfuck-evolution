#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Utils
{
 public:
  static void swap(int & a, int & b);
  static void swapc(char & a, char & b);
  static std::string int2str(int in);
  static int min(int a, int b);
  static int str2int(std::string in);
  static int randEx(int range_min, int range_max);
};

#endif
