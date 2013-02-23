#include <iostream>

#include "Exception.hpp"
#include "Individual.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  try
    {
      if(argc < 3)
	throw new Exception("To few arguments");

      cout << "Code:" << argv[1] << endl;
      Individual x(argv[1],argv[2]);
      cout << "Fitness: " << x.getFitness() << endl;
      cout << "Pattern: " << argv[2] << endl;
      cout << "Output : " << Interpreter::interpret(x.toString()) << endl;
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
