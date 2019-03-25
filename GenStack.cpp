#include "Genstack.h"
#include <iostream>

using namespace std;

GenStack::GenStack()//default constructor
{
  //initialize variable to default values
  myArray = new char[128];
  size = 128;
  top = -1;
}

GenStack::GenStack(int maxSize)//overloaded constructor
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack()//destructor
{
  delete myArray;
  delete size;
  delete top;
}

void GenStack::push(char d)
{
  //make sure stack is not full
  //you are responsible for error/bound checking
  myArray[++top] = d;
}

char GenStack::pop()
{
  //error checking (is it not empty)
  char temp = myArray[top--];
  return temp;
}

char GenStack::peek()
{
  //error checking
  return myArray[top];
}

bool GenStack::isFull()
{
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}

int GenStack::getSize()
{
  return top+1;
}
