#include <iostream>
#include "GenStack.cpp"
#include <string>
#include <vector>


using namespace std;

class syntaxChecker
{
  public:
    syntaxChecker();//constructor
    syntaxChecker(int maxSize);//overloaded constructor
    ~syntaxChecker();//destructor

    int readFile(string fileName);
    string line;
    string str;
    char ch;
    bool loop;
    int charCounter;
    int lineLength;
    int lineCounter;
    int lineTotal;
    //char delimitersVctr[500];
    vector<int> lineNumbers;
    string delimiters;
    //string lineNumbers;
};
