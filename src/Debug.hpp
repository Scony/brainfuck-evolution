#ifndef DEBUG_HPP
#define DEBUG_HPP

class Debug
{
  Debug();
public:
  int threshold;
  int generation;
  bool on;
  static Debug * instance();
};

#endif
