#ifndef BF_MEMORY
#define BF_MEMORY

class Memory
{
  struct Cell
  {
    unsigned char * cell;
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
  void write(unsigned char c);
  unsigned int read();
  void front();
};

#endif
