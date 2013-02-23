#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Utils
{
 public:
  static int abs(int in);
  static void swap(int & a, int & b);
  static void swapc(char & a, char & b);
  static void swapll(long long & a, long long & b);
  static std::string int2str(int in);
  static int min(int a, int b);
  static int str2int(std::string in);
  static double str2double(std::string in);
  static int randr(int range_min, int range_max);
  static double randd();
  static void invertll(long long * array, int left, int right);
};

#endif
