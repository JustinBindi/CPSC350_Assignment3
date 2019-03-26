#include "syntaxChecker.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace std;
syntaxChecker::syntaxChecker()//default constructor
{
  //initialize variable to default values

}

syntaxChecker::syntaxChecker(int maxSize)//overloaded constructor
{
  loop = true;
  charCounter = 0;
  delimiters = "";
  ch = '\0';
  lineCounter = 1;
  lineTotal = 0;
}

syntaxChecker::~syntaxChecker()//destructor
{

}

int syntaxChecker::readFile(string fileName)
{
  //GenStack<char> myStack(128);
  //GenStack<int> lineNumbers(128);
  //countChar = 0;
  //fileVector.clear();

  ifstream myFile (fileName);

  while(getline(myFile, line))
  {
    cout << line << endl;
    //charCounter++;
    lineLength = 0;

    lineLength = line.length()+1;
    //cout << lineLength << endl;
    lineTotal += lineLength;


    for (char ch : line)
    {
      charCounter++;
      if (ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '[' || ch == ']')
      {
        delimiters += ch;
        //lineNumbers += to_string(lineCounter);
        //delimitersVctr[0] = ch;
        //lineNumbersVctr[0] = lineCounter;
        //myStack.push(ch);
        lineNumbers.push_back(lineCounter);
        //cout << ch << endl;
      }
    }

    if (charCounter < lineTotal)
    {
      lineCounter++;
    }
  }
    //cout << charCounter << endl;
    //cout << ch << endl;
    cout << delimiters << endl;
    //cout << lineNumbers << endl;

    for (int i = 0; i < lineNumbers.size(); i++)
    {
      cout << lineNumbers[i] << endl;
    }

  //  while (loop)
    //{
      for (int i = 0; i < delimiters.length(); i++)
      {
        cout << i << delimiters << endl;

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
      //cout << delimiters[0] << endl;
      //cout << delimiters[delimiters.length()-1] << endl;

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
        //for (int i = 0; i < delimiters.length(); i++)
        //{
        if (!(delimiters[0] == '{' && delimiters[delimiters.length()-1] == '}' ||
            delimiters[0] == '(' && delimiters[delimiters.length()-1] == ')' ||
            delimiters[0] == '[' && delimiters[delimiters.length()-1] == ']'))
        {
          loop = false;
        }
      }
          cout << delimiters << endl;
          cout << lineNumbers[0] << endl;


      //}
  //}

    ////int size = myStack.getSize();
    //cout << size << endl;


    /*while (!myStack.isEmpty())
    {
      delimitersVctr[0] = myStack.pop();
    }

    while (!lineNumbers.isEmpty())
    {
      lineNumbersVctr[0] = lineNumbers.pop();
    }

    for (int i = 0; i < size; i++)
    {
      cout << delimitersVctr[i] << endl;
      cout << lineNumbersVctr[i] << endl;
    }

    for (const_iterator i = delimitersVctr.begin(); i != delimitersVctr.end(); ++i)
        cout << *i << ' ';
    for (const_iterator i = lineNumbersVctr.begin(); i != lineNumbersVctr.end(); ++i)
        cout << *i << ' ';

    for (auto const& value : delimitersVctr)
    {
        cout << value << endl;
    }
    for (auto const& value2 : lineNumbersVctr)
    {
        cout << value2 << endl;
    }*/


    //if (!line.empty())

    //cout << myArray << endl;


    //if (ch == '-' || ch == 'X' || ch == 'x')
    //{
      //countChar++;
      //fileVector.push_back(line);
    //}

  /*GenStack<string> reverseStack(myStack.getSize());
  while (!myStack.isEmpty())
  {
    reverseStack.push(myStack.pop());
  }

  while (!reverseStack.isEmpty())
  {
    str = "";
    str = (reverseStack.pop());
    for (char ch : str)
    {

    }
  }*/

  return 0;
}
