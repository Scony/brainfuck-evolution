#include "Exception.hpp"

using namespace std;

Exception::Exception(string message)
{
  this->message = message;
}

Exception::Exception()
{
  message = "Unknown exception";
}

string Exception::toString()
{
  return message;
}
