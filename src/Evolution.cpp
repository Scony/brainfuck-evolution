#include "Evolution.h"

using namespace std;

Evolution::Evolution(int argc, char ** argv, Client * client)
{
  if(argc < 4)
    throw new Exception("Too few arguments");

  this->algorithm = Utils::str2int(string(argv[3]));
  this->client = client;
  this->graph = new Graph(this->client->request("INIT"));
  this->startPopulation = Utils::str2int(client->request("STP"));
  this->populationCut = Utils::str2int(client->request("POP"));
  this->mutations = Utils::str2int(client->request("MUT"));
  this->frequence = Utils::str2int(client->request("FRQ"));

  switch(this->algorithm)
    {
    case 2:
      this->population.push_back(Box(new Heur(client->request("BST"),this->graph)));
      for(int i = 0; i < this->startPopulation; i++)
	population.push_back(Box(new Heur(this->graph)));
      break;
    default:
      this->population.push_back(Box(new Pmx(client->request("BST"),this->graph)));
      for(int i = 0; i < this->startPopulation; i++)
	population.push_back(Box(new Pmx(this->graph)));
    }
}

Evolution::~Evolution()
{
  delete this->graph;
}

void Evolution::run()
{
  int counter = 0;
  while(1)
    {
      //sort
      population.sort();
      cout << population.front().individual->getRate() << endl;

      //selection
      while(population.size() > (unsigned int)this->populationCut)
	{
	  delete population.back().individual;
	  population.pop_back();
	}

      //crossing over
      list<Box> newPopulation;
      for(list<Box>::iterator j = population.begin(); j != population.end(); j++)
      	for(list<Box>::iterator k = j; k != population.end(); k++)
      	  if(j != k)
      	    {
      	      pair<Individual*,Individual*> tmp = j->individual->crossingOver(*(k->individual));
      	      newPopulation.push_back(Box(tmp.first));
      	      newPopulation.push_back(Box(tmp.second));
      	    }
      while(!newPopulation.empty())
        {
      	  population.push_back(newPopulation.front());
      	  newPopulation.pop_front();
        }

      //sync
      if((++counter % this->frequence) == 0)
  	{
	  cout << "S" << endl;
  	  counter = 0;

	  switch(this->algorithm)
	    {
	    case 2:
	      population.push_back(Box(new Heur(client->request("IND " + population.front().individual->toString()),this->graph)));
	      break;
	    default:
	      population.push_back(Box(new Pmx(client->request("IND " + population.front().individual->toString()),this->graph)));
	      break;
	    }

	  this->populationCut = Utils::str2int(client->request("POP"));
	  this->mutations = Utils::str2int(client->request("MUT"));
	  this->frequence = Utils::str2int(client->request("FRQ"));
  	}

      //mutation
      for(list<Box>::iterator j = population.begin(); j != population.end(); j++)
      	if(Utils::randEx(1,100) <= this->mutations)
  	  j->individual->mutate();


    }
}
