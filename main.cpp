#include "GenStack.h"
#inlcude <iostream>

using namespace std;

int main (int argc, char **argv)
{
  GenStack myStack(10);
  //GenStack<int> myStack(22); //for a later build (more complex)

  myStack.push('R');
  myStack.push('E');
  myStack.push('N');
  myStack.push('E');

  cout << "popping :" << myStack.pop() << endl;
  cout << "peek :" << myStack.peek() << endl;

  myStack.push('F');
  cout << "peek :" << myStack.peek() << endl;

  while (!myStack.isEmpty())
  {
    cout << "popping :" << myStack.pop() << endl;
  }

  //cout << myStack.pop() << endl; //sometimes an error (stack is empty)

  return 0;
}
