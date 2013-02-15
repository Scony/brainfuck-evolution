#include <iostream>
#include <time.h>

#include "Exception.hpp"
#include "KindFactory.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      srand(time(0));
      KindFactory x(0,10,200,"xxxx");
      Individual * it = x.makeIndividual();
      cout << it->toString() << endl;
      delete it;
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
