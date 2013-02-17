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
      if(argc < 9)
	throw new Exception("To few arguments");
      srand(time(0));
      cout << "Pattern:" << argv[3] << endl;
      KindFactory pmx(Utils::str2int(argv[1]),Utils::str2int(argv[2]),Utils::str2int(argv[3]),argv[4]);
      IndividualFactory * ifac = &pmx;
      Evolution evolution(ifac,Utils::str2int(argv[5]),Utils::str2int(argv[6]),Utils::str2int(argv[7]),Utils::str2int(argv[8]));
      evolution.run();
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
