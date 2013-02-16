#include <stack>

#include "Interpreter.hpp"

using namespace std;

// Interpreter::Interpreter(string code)
// {
//   this->code = code;
//   hashLen = code.length();
//   hash = new int[hashLen];
//   stack<int> hill;
//   for(int i = 0; i < code.length(); i++)
//     {
//       if(code[i] == '[')
// 	hill.push(i);
//       if(code[i] == ']')
// 	if(hill.empty())
// 	  throw new Exception("Unexpected bracket !");
// 	else
// 	  {
// 	    hash[hill.top()] = i;
// 	    hash[i] = hill.top();
// 	    hill.pop();
// 	  }
//     }
//   if(!hill.empty())
//     throw new Exception("Too much brackets !");
// }

string Interpreter::interpret(string code)
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
      cout << "####" << i << "####\n";
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
	      //idz za odpowiedni zamykajacy
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
		i = code.length(); //global break
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
	    i = code.length(); //global break
      }
    }

  return out;
}
