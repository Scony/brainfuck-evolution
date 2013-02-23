#include <iostream>
#include <time.h>

#include "Debug.hpp"
#include "Exception.hpp"
#include "KindFactory.hpp"
#include "AlgorithmFactory.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      if(argc < 14)
	throw new Exception((string)"To few arguments. Usage:\n ./command [algorithm kind] [individual kind] [range begin]"
			    + (string)" [range end] [pattern] [initial size] [size] [q] [pc] [pm] [n] [debug] [mod]\n\n"
			    + (string)"1 - Roulette\n2 - Tournament\n3 - Basic RxR\n\n1 - Pmx\n2 - Sx\n3 - Rsx\n4 - Eru");
      srand(time(0));

      if(Utils::str2int(argv[12]))
	Debug::instance()->on = true;
      else
	Debug::instance()->on = false;
      Debug::instance()->threshold = Utils::str2int(argv[13]);

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
