#include <iostream>
#include <time.h>

#include "Exception.hpp"
#include "KindFactory.hpp"
#include "Evolution.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      srand(time(0));
      KindFactory pmx(1,50,100,"hi");
      IndividualFactory * ifac = &pmx;
      Evolution evolution(ifac);
      evolution.run();
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
