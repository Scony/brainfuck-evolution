#include "Debug.hpp"

Debug::Debug()
{
  threshold = 100;
  generation = 0;
  on = true;
}

Debug * Debug::instance()
{
  static Debug d;
  return &d;
}
