#include <iostream>

#include "Exception.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      cout << "ok";
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
