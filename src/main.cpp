#include <iostream>
#include <time.h>

#include "Exception.hpp"
#include "KindFactory.hpp"
#include "Genetic.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      if(argc < 11)
	throw new Exception((string)"To few arguments. Usage:\n ./command [individual kind] [range begin] [range end] [pattern]"
			    + (string)" [initial size] [size] [q] [pc] [pm] [n]");
      srand(time(0));
      cout << "Pattern:" << argv[4] << endl;
      KindFactory kf(Utils::str2int(argv[1]),Utils::str2int(argv[2]),Utils::str2int(argv[3]),argv[4]);
      IndividualFactory * ifac = &kf;
      Genetic genetic(
		      ifac,
		      Utils::str2int(argv[5]),
		      Utils::str2int(argv[6]),
		      Utils::str2int(argv[7]),
		      Utils::str2double(argv[8]),
		      Utils::str2double(argv[9]),
		      Utils::str2int(argv[10])
		      );
      genetic.run();
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
