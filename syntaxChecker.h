#include <iostream>
#include "GenStack.cpp"
#include <string>
#include <vector>


using namespace std;

class syntaxChecker
{
  public:
    syntaxChecker();//constructor
    syntaxChecker(int value);//overloaded constructor
    ~syntaxChecker();//destructor

    int Checker(string fileName);
    string line;
    char ch;
    bool loop;
    int charCounter;
    int lineLength;
    int lineCounter;
    int lineTotal;
    vector<int> lineNumbers;
    string delimiters;
};
