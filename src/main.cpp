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
      if(argc < 7)
	throw new Exception("To few arguments");
      srand(time(0));
      cout << "Pattern:" << argv[3] << endl;
      KindFactory pmx(1,Utils::str2int(argv[1]),Utils::str2int(argv[2]),argv[3]);
      IndividualFactory * ifac = &pmx;
      // Individual * x = pmx.makeIndividual();
      // cout << x->toString() << "::" << x->getRate() << endl;
      Evolution evolution(ifac,Utils::str2int(argv[4]),Utils::str2int(argv[5]),Utils::str2int(argv[6]));
      evolution.run();
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
