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
      if(argc < 6)
	throw new Exception("To few arguments");

      srand(time(0));
      cout << "Pattern:" << argv[4] << endl;
      KindFactory kf(Utils::str2int(argv[1]),Utils::str2int(argv[2]),Utils::str2int(argv[3]),argv[4]);
      Individual * a = kf.makeIndividual();
      Individual * b = kf.makeIndividual();

      cout << a->toString() << " ";
      cout << b->toString() << endl;

      // a->mutate(Utils::str2double(argv[5]));
      // b->mutate(Utils::str2double(argv[5]));

      // cout << a->toString() << endl;
      // cout << b->toString() << endl;

      list<Individual::Box> lst = a->crossingOver(*b);
      for(list<Individual::Box>::iterator i = lst.begin(); i != lst.end(); i++)
	cout << i->individual->toString() << " ";
      cout << endl;
    }
  catch(Exception * e)
    {
      cout << e->toString() << endl;
      delete e;
    }

  return 0;
}
