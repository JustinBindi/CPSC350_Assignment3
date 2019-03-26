#include "syntaxChecker.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace std;
syntaxChecker::syntaxChecker()//default constructor
{
  //initialize variable to default values
  loop = true;
  charCounter = 0;
  delimiters = "";
  ch = '\0';
  lineCounter = 1;
  lineTotal = 0;
}

syntaxChecker::syntaxChecker(int value)//overloaded constructor
{
  loop = true;
  charCounter = value;
  delimiters = "";
  ch = '\0';
  lineCounter = 1;
  lineTotal = value;
}

syntaxChecker::~syntaxChecker()//destructor
{
  //delete lineNumbers
}

//Functionality to read the lines from a file and determine if there are
//any missing or wrong delimeters.
int syntaxChecker::Checker(string fileName)
{
  ifstream myFile (fileName);

  while(getline(myFile, line))
  {
    lineLength = 0;
    lineLength = line.length()+1;
    lineTotal += lineLength;

    for (char ch : line)
    {
      charCounter++;
      if (ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '[' || ch == ']')
      {
        delimiters += ch;
        lineNumbers.push_back(lineCounter);
      }
    }

    if (charCounter < lineTotal)
    {
      lineCounter++;
    }
  }
      for (int i = 0; i < delimiters.length(); i++)
      {
        if (delimiters[i] == '(' && delimiters[i+1] == ')')
        {
          delimiters.erase(i+1,1);
          delimiters.erase(i,1);
          lineNumbers.erase(lineNumbers.begin()+i+1,lineNumbers.begin()+i+2);
          lineNumbers.erase(lineNumbers.begin()+i,lineNumbers.begin()+i+1);
          i = -1;
        }
        if (delimiters[i] == '[' && delimiters[i+1] == ']')
        {
          delimiters.erase(i+1,1);
          delimiters.erase(i,1);
          lineNumbers.erase(lineNumbers.begin()+i+1,lineNumbers.begin()+i+2);
          lineNumbers.erase(lineNumbers.begin()+i,lineNumbers.begin()+i+1);
          i = -1;
        }
        if (delimiters[i] == '{' && delimiters[i+1] == '}')
        {
          delimiters.erase(i+1,1);
          delimiters.erase(i,1);
          lineNumbers.erase(lineNumbers.begin()+i+1,lineNumbers.begin()+i+2);
          lineNumbers.erase(lineNumbers.begin()+i,lineNumbers.begin()+i+1);
          i = -1;
        }
      }

      while (loop)
      {
        while (delimiters[0] == '{' && delimiters[delimiters.length()-1] == '}')
        {
          delimiters.pop_back();
          delimiters.erase(delimiters.begin());
          lineNumbers.pop_back();
          lineNumbers.erase(lineNumbers.begin());
        }
        while (delimiters[0] == '(' && delimiters[delimiters.length()-1] == ')')
        {
          delimiters.pop_back();
          delimiters.erase(delimiters.begin());
          lineNumbers.pop_back();
          lineNumbers.erase(lineNumbers.begin());
        }
        while (delimiters[0] == '[' && delimiters[delimiters.length()-1] == ']')
        {
          delimiters.pop_back();
          delimiters.erase(delimiters.begin());
          lineNumbers.pop_back();
          lineNumbers.erase(lineNumbers.begin());
        }
        if (!(delimiters[0] == '{' && delimiters[delimiters.length()-1] == '}' ||
            delimiters[0] == '(' && delimiters[delimiters.length()-1] == ')' ||
            delimiters[0] == '[' && delimiters[delimiters.length()-1] == ']'))
        {
          loop = false;
        }
      }

      //prints the results of the search
      if (delimiters[0] == '{' || delimiters[0] == '(' || delimiters[0] == '[')
      {
        if (delimiters[0] == '{')
        {
          cout << "Line " << lineNumbers[1] << ": expected } and found " << delimiters[1] << endl;
        }
        if (delimiters[0] == '(')
        {
          cout << "Line " << lineNumbers[1] << ": expected ) and found " << delimiters[1] << endl;
        }
        if (delimiters[0] == '[')
        {
          cout << "Line " << lineNumbers[1] << ": expected ] and found " << delimiters[1] << endl;
        }
      }

      if (delimiters[0] == '}' || delimiters[0] == ')' || delimiters[0] == ']')
      {
        cout << "Line " << lineNumbers[0] << ": found " << delimiters[0] << " and no opening delimeter" << endl;
      }

  return 0;
}
