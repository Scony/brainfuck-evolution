#include "Utils.hpp"

using namespace std;

int Utils::abs(int in)
{
  return in >= 0 ? in : -in;
}

void Utils::swap(int & a, int & b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

void Utils::swapc(char & a, char & b)
{
  char tmp = a;
  a = b;
  b = tmp;
}

void Utils::swapll(long long & a, long long & b)
{
  long long tmp = a;
  a = b;
  b = tmp;
}

string Utils::int2str(int in)
{
  char buff[16];
  sprintf(buff,"%d",in);
  return string(buff);
}

int Utils::min(int a, int b)
{
  return a < b ? a : b;
}

int Utils::str2int(string in)
{
  int out;
  sscanf(in.c_str(),"%d",&out);
  return out;
}

double Utils::str2double(std::string in)
{
  double out;
  sscanf(in.c_str(),"%lf",&out);
  return out;
}

int Utils::randr(int range_min, int range_max)
{
  int tmp_range;
  if ( range_max >= range_min ) range_max -= range_min;
  else
    {
      tmp_range = range_min - range_max;
      range_min = range_max;
      range_max = tmp_range;
    }
  return (int)(range_max ? range_min + rand() / (RAND_MAX + 1.0) * (double) (range_max + 1) : range_min);
}

double Utils::randd()
{
  return (double)rand() / RAND_MAX;
}

void Utils::invertll(long long * array, int left, int right)
{
  if(left < right)
    {
      Utils::swapll(array[left],array[right]);
      invertll(array,left+1,right-1);
    }
}
