#include <iostream>
#include <time.h>

#include "Exception.hpp"
#include "KindFactory.hpp"
#include "AlgorithmFactory.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      if(argc < 12)
	throw new Exception((string)"To few arguments. Usage:\n ./command [individual kind] [range begin] [range end] [pattern]"
			    + (string)" [initial size] [size] [q] [pc] [pm] [n]");
      srand(time(0));
      cout << "Pattern:" << argv[5] << endl;
      KindFactory kf(Utils::str2int(argv[2]),Utils::str2int(argv[3]),Utils::str2int(argv[4]),argv[5]);
      IndividualFactory * ifac = &kf;
      AlgorithmFactory af(
		      Utils::str2int(argv[1]),
		      ifac,
		      Utils::str2int(argv[6]),
		      Utils::str2int(argv[7]),
		      Utils::str2int(argv[8]),
		      Utils::str2double(argv[9]),
		      Utils::str2double(argv[10]),
		      Utils::str2int(argv[11])
		      );
      Evolution * algorithm = af.makeAlgorithm();
      algorithm->run();
      delete algorithm;
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
