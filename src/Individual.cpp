#include "Individual.h"

using namespace std;

int Individual::randEx(int range_min, int range_max)
{
  int tmp_range;
  if ( range_max >= range_min ) range_max -= range_min;
  else
    {
      tmp_range = range_min - range_max;
      range_min = range_max;
      range_max = tmp_range;
    }
  return (int)(range_max ? range_min + rand() / (RAND_MAX + 1.0) * (double) (range_max + 1) : range_min);
}

void Individual::swap(int & a, int & b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

void Individual::eval()
{
  this->rate = 0;

  for(int i = 1; i < this->n; i++)
    this->rate += this->graph->getDistance(ord[i-1],ord[i]);
  this->rate += this->graph->getDistance(ord[n-1],ord[0]);
}

Individual::Individual(Graph * graph)
{
  this->graph = graph;
  this->n = graph->getN();
  this->ord = new int[this->n];
  for(int i = 0; i < this->n; i++)
    ord[i] = i;
  this->shuffle();
  this->eval();
}

Individual::Individual(std::string individual, Graph * graph)
{
  this->graph = graph;

  stringstream ss;
  ss << individual;

  ss >> this->n;
  this->ord = new int[this->n];

  for(int i = 0; i < this->n; i++)
    ss >> this->ord[i];

  this->eval();
}

Individual::Individual(int n, Graph * graph, int * ord)
{
  this->n = n;
  this->graph = graph;
  this->ord = new int[n];
  for(int i = 0; i < n; i++)
    this->ord[i] = ord[i];
  this->eval();
}

Individual::Individual(const Individual & individual)
{
  this->n = individual.n;
  this->rate = individual.rate;
  this->graph = individual.graph;
  this->ord = new int[n];
  for(int i = 0; i < n; i++)
    this->ord[i] = individual.ord[i];
}

Individual::~Individual()
{
  delete [] ord;
}

bool Individual::operator<(const Individual & individual) const
{
  return this->rate < individual.rate;
}

std::pair<Individual*,Individual*> Individual::crossingOver(Individual & other)
{
  Individual * a = new Individual(*this);
  Individual * b = new Individual(*this);

  return pair<Individual*,Individual*>(a,b);
}

void Individual::mutate()
{
  //
}

long long Individual::getRate()
{
  return this->rate;
}

int Individual::getOrd(int index)
{
  return this->ord[index];
}

string Individual::toString()
{
  char buff[16];
  sprintf(buff,"%d ",this->n);
  string out = string(buff);
  for(int i = 0; i < this->n; i++)
    {
      sprintf(buff,"%d ",this->ord[i]);
      out += string(buff);
    }
  return out;
}

void Individual::shuffle()
{
  for(int i = 1; i < this->n; i++)
    {
      int k = randEx(1,this->n-1);
      swap(ord[i],ord[k]);
    }
  this->eval();
}
