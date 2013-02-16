#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(IndividualFactory * factory)
{
  this->factory = factory;

  startPopulation = 50;
  populationCut = 30;
  mutations = 70;

  makePopulation();
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
  int counter = 0;
  while(1)
    {
      //sort
      population.sort();
      cout << population.size() << "::" << population.front().individual->getRate() << "::" << Interpreter::interpret(population.front().individual->toString()).substr(0,10) << "::" << endl;

      //selection
      while(population.size() > (unsigned int)populationCut)
	{
	  population.back().remove();
	  population.pop_back();
	}

      //crossing over
      list<Individual::Box> newPopulation;
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
      	for(list<Individual::Box>::iterator j = i; j != population.end(); j++)
      	  if(i != j)
      	    {
	      list<Individual::Box> crossProducts = i->individual->crossingOver(*(j->individual));
	      // mozna w nawiasie                /\
	      while(!crossProducts->empty())
		{
		  newPopulation.push_back(crossProducts.front());
		  crossProducts.pop_front();
		}
      	    }
      while(!newPopulation.empty())
        {
      	  population.push_back(newPopulation.front());
      	  newPopulation.pop_front();
        }

      //mutation
      for(list<Individual::Box>::iterator i = population.begin(); i != population.end(); i++)
      	if(Utils::randEx(1,100) <= mutations)
  	  i->individual->mutate();


    }
}

void Evolution::makePopulation()
{
  for(int i = 0; i < startPopulation; i++)
    population.push_back(factory->makeIndividual()->box());
}
