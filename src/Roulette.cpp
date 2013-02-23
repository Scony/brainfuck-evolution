#include "Roulette.hpp"
#include "Debug.hpp"

using namespace std;

Roulette::Roulette(IndividualFactory * factory) : Evolution(factory)
{
  pc = 0.9;
  pm = 0.01;
  n = 2;
}

Roulette::Roulette(IndividualFactory * factory, int initialSize, int size,
		   double pc, double pm, int n) : Evolution(factory,initialSize,size)
{
  this->pc = pc;
  this->pm = pm;
  this->n = n;
}

Roulette::~Roulette()
{
}

void Roulette::run()
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

      // roulette preselection & crossing over
      long long sum[population.size()];
      Individual * ptr[population.size()];
      int it = 0;
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
  	{
  	  sum[it] = i->individual->getFitness();
  	  ptr[it++] = i->individual;
  	}
      Utils::invertll(sum,0,population.size()-1);
      for(int i = 1; i < population.size(); i++)
  	sum[i] += sum[i-1];

      list<Individual::Box> newPopulation;
      while(newPopulation.size() < size)
  	{
  	  int a = Utils::randr(0,sum[population.size()-1]-1);
  	  int b = Utils::randr(0,sum[population.size()-1]-1);
  	  int aIt = 0;
  	  int bIt = 0;
  	  while(a >= sum[aIt])
  	    aIt++;
  	  while(b >= sum[bIt])
  	    bIt++;
	  if(Utils::randd() <= pc) // crossing over with pc
	    {
	      list<Individual::Box> crossProducts = ptr[aIt]->crossingOver(*(ptr[bIt]));
	      while(!crossProducts.empty())
		{
		  newPopulation.push_back(crossProducts.front());
		  crossProducts.pop_front();
		}
	    }
	  else
	    {
	      newPopulation.push_back(ptr[aIt]->clone()->box());
	      newPopulation.push_back(ptr[bIt]->clone()->box());
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
