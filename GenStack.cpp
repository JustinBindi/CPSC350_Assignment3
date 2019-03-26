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
  //delete *size;
  //delete *top;
}

template <class T>
int GenStack<T>::push(T d)
{
  //make sure stack is not full
  //you are responsible for error/bound checking
  if (!isFull())
  {
    myArray[++top] = d;
    return 0;
  }
  else
  {
    size += size;
    doubleArray = new T[size];
    //for (T item& : myArray)
    //{
    /*while (!top == -1)
    {
      T temp = myArray[top--];
      doubleArray[0] = temp;
    }*/
    doubleArray = myArray;
    cout << myArray << endl;
    cout << doubleArray << endl;
    cout << sizeof(doubleArray) << endl;
    //delete myArray;

    myArray = new T[size];

    myArray = doubleArray;
    cout << myArray << endl;
    cout << sizeof(myArray) << endl;

    myArray[++top] = d;
    cout << myArray << endl;
    cout << sizeof(myArray) << endl;
    /*while (!top == -1)
    {
      T temp = doubleArray[top--];
      myArray[0] = temp;
    }*/



    //doubleArray[0] = myArray.pop();
    //}

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
  return myArray[top];
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
