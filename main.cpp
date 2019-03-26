#include "syntaxChecker.cpp"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  //GenStack<char> myStack(3);
  string fileName;
  syntaxChecker checker(128);

  //GenStack<int> myStack(22); //for a later build (more complex)
  try
  {
    //myStack.pop();


    cin >> fileName;
    checker.readFile(fileName);
    //readFile(fileName);

    /*myStack.push('R');
    myStack.push('E');
    myStack.push('N');
    myStack.push('E');

    cout << "popping :" << myStack.pop() << endl;
    cout << "peek :" << myStack.peek() << endl;

    myStack.push('F');
    cout << "peek :" << myStack.peek() << endl;

    myStack.push('Q');
    cout << "peek :" << myStack.peek() << endl;

    while (!myStack.isEmpty())
    {
      cout << "popping :" << myStack.pop() << endl;
    }*/

    //cout << myStack.pop() << endl; //sometimes an error (stack is empty)
  }
  catch (const char* msg)
  {
    cout << msg << endl;
  }

  return 0;
}
