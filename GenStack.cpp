#include "Genstack.h"
#include <iostream>
#include <array>

using namespace std;
template <class T>
GenStack<T>::GenStack()//default constructor
{
  //initialize variable to default values
  myArray = new T[128];
  size = 128;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize)//overloaded constructor
{
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack()//destructor
{
  //delete myArray;
}

template <class T>
int GenStack<T>::push(T d)
{
  //make sure stack is not full
  if (!isFull())
  {
    myArray[++top] = d;
    return 0;
  }
  else
  {
    size += size;
    doubleArray = new T[size];
    doubleArray = myArray;
    cout << myArray << endl;
    cout << doubleArray << endl;
    cout << sizeof(doubleArray) << endl;

    myArray = new T[size];

    myArray = doubleArray;
    cout << myArray << endl;
    cout << sizeof(myArray) << endl;

    myArray[++top] = d;
    cout << myArray << endl;
    cout << sizeof(myArray) << endl;
  }
  return 0;
}

template <class T>
T GenStack<T>::pop()
{
  //error checking (is it not empty)
  if (!isEmpty())
  {
    T temp = myArray[top--];
    return temp;
  }
  else
  {
    throw "Stack is Empty EXCEPTION!";
  }
}

template <class T>
T GenStack<T>::peek()
{
  //error checking
  if (!isEmpty())
  {
    return myArray[top];
  }
  else
  {
    throw "Stack is Empty EXCEPTION!";
  }
}

template <class T>
bool GenStack<T>::isFull()
{
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize()
{
  return top+1;
}
