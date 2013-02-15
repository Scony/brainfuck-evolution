#include "Pmx.h"

using namespace std;

Pmx::Pmx(Graph * graph) : Individual(graph)
{
}

Pmx::Pmx(string individual, Graph * graph) : Individual(individual,graph)
{
}

Pmx::Pmx(int n, Graph * graph, int * ord) : Individual(n,graph,ord)
{
}

Pmx::Pmx(const Pmx & pmx) : Individual(pmx)
{
}

Pmx::~Pmx()
{
}

void Pmx::inv(int left, int right)
{
  if(left<right)
    {
      swap(ord[left],ord[right]);
      inv(left+1,right-1);
    }
}

pair<Individual*,Individual*> Pmx::crossingOver(Individual & x)
{
  int l = randEx(1,n-1), r = randEx(1,n-1);
  if(l>r)
    swap(l,r);
  Pmx * a = new Pmx(this->graph);
  Pmx * b = new Pmx(this->graph);
  int hashA[n], hashB[n];
  for(int i = 0; i < n; i++)
    {
      hashA[i] = -1;
      hashB[i] = -1;
    }
  for(int i = l; i <= r; i++)
    {
      a->ord[i] = x.getOrd(i);
      b->ord[i] = ord[i];
      hashA[x.getOrd(i)] = ord[i];
      hashB[ord[i]] = x.getOrd(i);
    }
  for(int i = 0; i < l; i++)
    {
      if(hashA[ord[i]]==-1)
	a->ord[i] = ord[i];
      else
	{
	  a->ord[i] = hashA[ord[i]];
	  while(hashA[a->ord[i]]!=-1)
	    a->ord[i] = hashA[a->ord[i]];
	}
      if(hashB[x.getOrd(i)]==-1)
	b->ord[i] = x.getOrd(i);
      else
	{
	  b->ord[i] = hashB[x.getOrd(i)];
	  while(hashB[b->ord[i]]!=-1)
	    b->ord[i] = hashB[b->ord[i]];
	}
    }
  for(int i = r + 1; i < n; i++)
    {
      if(hashA[ord[i]]==-1)
	a->ord[i] = ord[i];
      else
	{
	  a->ord[i] = hashA[ord[i]];
	  while(hashA[a->ord[i]]!=-1)
	    a->ord[i] = hashA[a->ord[i]];
	}
      if(hashB[x.getOrd(i)]==-1)
	b->ord[i] = x.getOrd(i);
      else
	{
	  b->ord[i] = hashB[x.getOrd(i)];
	  while(hashB[b->ord[i]]!=-1)
	    b->ord[i] = hashB[b->ord[i]];
	}
    }
  a->eval();
  b->eval();

  return pair<Individual*,Individual*>(a,b);
}

void Pmx::mutate()
{
  int a = randEx(1,n-1), b = randEx(1,n-1);
  if(a<b)
    inv(a,b);
  else
    inv(b,a);
  eval();
}
