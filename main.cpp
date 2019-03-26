#include "syntaxChecker.cpp"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  string fileName;
  syntaxChecker checker(0);

  try
  {
    cout << "Please insert a file name:" << endl;
    cin >> fileName;
    checker.Checker(fileName);
  }
  catch (const char* msg)
  {
    cout << msg << endl;
  }

  return 0;
}
