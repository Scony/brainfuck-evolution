#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(IndividualFactory * factory)
{
  this->factory = factory;

  startPopulation = 100;
  populationCut = 50;
  mutations = 100;

  makePopulation();
}

Evolution::Evolution(IndividualFactory * factory, int startPopulation,
		     int populationCut, int mutations)
{
  this->factory = factory;

  this->startPopulation = startPopulation;
  this->populationCut = populationCut;
  this->mutations = mutations;

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
      cout << population.size() << "::" << population.front().individual->getRate() << "::";
      cout << Interpreter::interpret(population.front().individual->toString()).substr(0,10) << "::" << population.front().individual->toString() << endl;

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
	      // cout << "/" << crossProducts.size() << "\\";
	      while(!crossProducts.empty())
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
