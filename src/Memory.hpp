#ifndef BF_MEMORY
#define BF_MEMORY

class Memory
{
  struct Cell
  {
    unsigned int * cell;
    Cell * next;
    Cell * previous;
    Cell();
    ~Cell();
  };
  Cell * head;
  Cell * ptr;
public:
  Memory();
  ~Memory();
  void add();
  void sub();
  void next();
  void previous();
  unsigned int read();
  void front();
};

#endif
