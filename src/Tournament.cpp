#include "Tournament.hpp"
#include "Debug.hpp"

using namespace std;

Tournament::Tournament(IndividualFactory * factory) : Evolution(factory)
{
  q = 5;
  pc = 0.9;
  pm = 0.01;
  n = 2;
}

Tournament::Tournament(IndividualFactory * factory, int initialSize, int size, int q,
		       double pc, double pm, int n) : Evolution(factory,initialSize,size)
{
  this->q = q > 0 ? q : 1;
  this->pc = pc;
  this->pm = pm;
  this->n = n;
}

Tournament::~Tournament()
{
}

void Tournament::run()
{
  while(1)
    {
      // sort
      population.sort();
      if(Debug::instance()->on)
	{
	  cout << population.size() << "::" << population.front().individual->getFitness() << "::";
	  cout << population.front().individual->toString();
	  for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
	    cout << " " << i->individual->getFitness();
	  cout << endl;
	}
      else
	{
	  Debug::instance()->generation++;
	  if(!(Debug::instance()->generation % Debug::instance()->threshold))
	    {
	      cout << population.size() << "::" << population.front().individual->getFitness() << "::";
	      cout << "::" << population.front().individual->toString();
	      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
		cout << " " << i->individual->getFitness();
	      cout << endl;
	    }
	}

      // cut
      while(population.size() > size)
	{
	  population.back().remove();
	  population.pop_back();
	}

      // tournament preselection & crossing over
      Individual * ptr[population.size()];
      int it = 0;
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
	ptr[it++] = i->individual;

      list<Individual::Box> newPopulation;
      while(newPopulation.size() < size)
  	{
	  list<Individual::Box> tournament1;
	  list<Individual::Box> tournament2;
	  while(tournament1.size() < q)
	    tournament1.push_back(ptr[Utils::randr(0,population.size()-1)]->box());
	  while(tournament2.size() < q)
	    tournament2.push_back(ptr[Utils::randr(0,population.size()-1)]->box());
	  tournament1.sort();
	  tournament2.sort();

	  if(Utils::randd() <= pc) // crossing over with pc
	    {
	      list<Individual::Box> crossProducts = tournament1.front().individual->crossingOver(*(tournament2.front().individual));
	      while(!crossProducts.empty())
		{
		  newPopulation.push_back(crossProducts.front());
		  crossProducts.pop_front();
		}
	    }
	  else
	    {
	      newPopulation.push_back(tournament1.front().individual->clone()->box());
	      newPopulation.push_back(tournament2.front().individual->clone()->box());
	    }
  	}

      // mutations with pm
      for(list<Individual::Box>::iterator i = newPopulation.begin(); i != newPopulation.end(); i++)
	i->individual->mutate(pm);

      // postselection keeping n
      while(population.size() > n)
        {
      	  population.back().remove();
      	  population.pop_back();
        }

      // merge
      // Tt + nPt -> Ot -> Pt+1
      while(!newPopulation.empty())
        {
      	  population.push_back(newPopulation.front());
      	  newPopulation.pop_front();
        }
    }
}
