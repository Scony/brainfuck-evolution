#include <stack>

#include "Interpreter.hpp"

using namespace std;

string Interpreter::interpret(string & code)
{
  Memory memory;

  int hashLen = code.length();
  int hash[hashLen];
  for(int i = 0; i < hashLen; i++)
    hash[i] = 0;

  stack<int> hill;

  string out = "";

  for(int i = 0; i < code.length(); i++)
    {
      switch(code[i])
	{
	case '+':
	  memory.add();
	  break;
	case '-':
	  memory.sub();
	  break;
	case '>':
	  memory.next();
	  break;
	case '<':
	  memory.previous();
	  break;
	case ',':
	  memory.write(255);
	  break;
	case '.':
	  out += (char)memory.read();
	  break;
	case '[':
	  if(!memory.read())
	    {
	      int bCount = 0;
	      int j = i + 1;
	      i = code.length();
	      for(; j < code.length(); j++)
		{
		  if(code[j] == '[')
		    bCount++;
		  if(code[j] == ']')
		    {
		      if(!bCount)
			{
			  i = j;
			  break;
			}
		      bCount--;
		    }
		}
	    }
	  else
	    {
	      hill.push(i);
	      hash[i]++;
	      if(hash[i] > LOOP_CUT)
		{
		  int bCount = 0;
		  code[i] = '0';
		  int j = i + 1;
		  for(; j < code.length(); j++)
		    {
		      if(code[j] == '[')
			bCount++;
		      if(code[j] == ']')
			{
			  if(!bCount)
			    {
			      i = j;
			      break;
			    }
			  bCount--;
			}
		      code[j] = '0';
		    }
		  if(j < code.length())
		    code[j] = '0';
		}
	    }
	  break;
	case ']':
	  if(!hill.empty())
	    {
	      if(memory.read())
		{
		  i = hill.top() - 1;
		  hill.pop();
		}
	    }
	  else
	    code[i] = '0';
	}
    }

  return out;
}
