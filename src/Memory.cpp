#include <iostream>

#include "Memory.hpp"

using namespace std;

Memory::Cell::Cell()
{
  cell = new unsigned char(0);
  next = NULL;
  previous = NULL;
}

Memory::Cell::~Cell()
{
  delete cell;
  if(next)
    {
      next->previous = NULL;
      delete next;
    }
  if(previous)
    {
      previous->next = NULL;
      delete previous;
    }
}

Memory::Memory()
{
  ptr = head = new Cell;
}

Memory::~Memory()
{
  delete head;
}

void Memory::add()
{
  (*(ptr->cell))++;
}

void Memory::sub()
{
  (*(ptr->cell))--;
}

void Memory::next()
{
  if(ptr->next)
    ptr = ptr->next;
  else
    {
      ptr->next = new Cell;
      ptr->next->previous = ptr;
      ptr = ptr->next;
    }
}

void Memory::previous()
{
  //move head to left border ?
  if(ptr->previous)
    ptr = ptr->previous;
  else
    {
      ptr->previous = new Cell;
      ptr->previous->next = ptr;
      ptr = ptr->previous;
    }
}

void Memory::write(unsigned char c)
{
  *ptr->cell = c;
}

unsigned int Memory::read()
{
  return *ptr->cell;
}

void Memory::front()
{
  ptr = head;
}
