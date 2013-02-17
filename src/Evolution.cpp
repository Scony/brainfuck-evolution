#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(IndividualFactory * factory)
{
  this->factory = factory;

  startPopulation = 100;
  populationCut = 50;
  mutations = 100;
  injections = 0;

  fillPopulation(startPopulation);
}

Evolution::Evolution(IndividualFactory * factory, int startPopulation,
		     int populationCut, int mutations, int injections)
{
  this->factory = factory;

  this->startPopulation = startPopulation;
  this->populationCut = populationCut;
  this->mutations = mutations;
  this->injections = injections;

  fillPopulation(startPopulation);
}

Evolution::~Evolution()
{
  while(population.size())
    {
      population.back().remove();
      population.pop_back();
    }
}

void Evolution::run()
{
  while(1)
    {
      //sort
      population.sort();
      cout << population.size() << "::" << population.front().individual->getRate() << "::";
      cout << Interpreter::interpret(population.front().individual->toString()).substr(0,10) << "::" << population.front().individual->toString() << endl;

      //selection & crossing over
      long long sum[population.size()];
      Individual * ptr[population.size()];
      int it = 0;
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
	{
	  sum[it] = i->individual->getRate();
	  ptr[it++] = i->individual;
	}
      Utils::invertll(sum,0,population.size()-1);
      for(int i = 1; i < population.size(); i++)
	sum[i] += sum[i-1];

      list<Individual::Box> newPopulation;
      while(newPopulation.size() < populationCut)
	{
	  //cTODO: avoid self-crossing
	  int a = Utils::randEx(0,sum[population.size()-1]-1);
	  int b = Utils::randEx(0,sum[population.size()-1]-1);
	  int aIt = 0;
	  int bIt = 0;
	  while(a >= sum[aIt])
	    aIt++;
	  while(b >= sum[bIt])
	    bIt++;
	  list<Individual::Box> crossProducts = ptr[aIt]->crossingOver(*(ptr[bIt]));
	  while(!crossProducts.empty())
	    {
	      newPopulation.push_back(crossProducts.front());
	      crossProducts.pop_front();
	    }
	}

      while(!population.empty())
        {
      	  population.front().remove();
      	  population.pop_front();
        }

      while(!newPopulation.empty())
        {
      	  population.push_back(newPopulation.front());
      	  newPopulation.pop_front();
        }

      //injection
      fillPopulation(injections);

      //mutation
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
      	if(Utils::randEx(1,100) <= mutations)
  	  i->individual->mutate();


    }
}

void Evolution::fillPopulation(int count)
{
  for(int i = 0; i < count; i++)
    population.push_back(factory->makeIndividual()->box());
}
