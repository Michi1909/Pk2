#include "stack.h"
#include <string>
#include <iostream>

using namespace std_Stack;

int main()
{
  //Stack s;

  Stack<string> *s = new Stack<string>{};
  try
  {
    s->pop();
  }
  catch (empty_stack_exception e)
  {
    cout << e.what() << endl;
  }

  s->push("1");
  cout << s->pop() << endl;
  //delete s;
  return 0;
}